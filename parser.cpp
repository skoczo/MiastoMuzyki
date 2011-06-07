#include "parser.h"

/*
 Put station name, station id and station url to map
 */
Parser::Parser() {
	stacje = new QMap<QString, QString> ;
	identyfikatory = new QMap<QString, QString> ;
}

/*
 this function parse all.pls file
 and put information from this file
 to maps
 */
void Parser::start() {
	access = new QNetworkAccessManager(this);

	//when download data is finished finished slot is called
	connect(access, SIGNAL(finished(QNetworkReply*)), this,
			SLOT(finished(QNetworkReply*)));

	QString url = "http://skoczo.pl/all.pls";
	access->get(QNetworkRequest(url));
}

void Parser::finished(QNetworkReply *reply) {
	//if no error
	if (reply->error() == 0) {
		QString stat(reply->readAll());

		//variable for remember file name
		QString file, ident;

		for (int i = 0; i < stat.length(); i++) {
			if (stat[i] == '\n')
				continue;

			//variable for help
			QString tmp = "";
			tmp.append(stat[i]);
			i++;

			//get first three chars
			for (int j = 0; j < 3 && i < stat.length(); j++) {
				tmp.append(stat[i]);
				i++;
			}

			//if it`s file
			if (tmp == "File") {
				//gets all chars to '=' char
				while (stat[i] != '=') {
					i++;

					if (i >= stat.length())
						break;
				}

				//clear tmp
				tmp = "";

				i++;

				while (stat[i] != '\n' && i < stat.length()) {
					//remember chars to string
					tmp.append(stat[i]);
					i++;
				}

				//remember result
				file = tmp;
			}

			if (tmp == "Iden") {
				//gets all chars to '=' char
				while (stat[i] != '=') {
					i++;

					if (i >= stat.length())
						break;
				}

				//clear tmp
				tmp = "";

				i++;
				while (stat[i] != '\n' && i < stat.length()) {
					//remember chars to string
					tmp.append(stat[i]);
					i++;
				}
				//remember result
				ident = tmp;
			}

			//if this is title
			if (tmp == "Titl") {
				//gets all chars to '=' char
				while (stat[i] != '=') {
					i++;

					if (i >= stat.length())
						break;
				}

				//clear tmp
				tmp = "";

				i++;
				while (stat[i] != '\n' && i < stat.length()) {
					//remember chars to string
					tmp.append(stat[i]);
					i++;
				}
				//remember results to map
				(*stacje)[tmp] = file;
				(*identyfikatory)[tmp] = ident;
			}
		}
		qDebug("Stations list parsed");
		emit send(stacje, identyfikatory);
	}
	//if error send NULL
	else {
		qDebug() << ("Stations load failed " + reply->errorString());
		emit fail();
	}
}
