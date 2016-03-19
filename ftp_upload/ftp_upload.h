#ifndef FTP_UPLOAD_H
#define FTP_UPLOAD_H

#include <QtGui/QWidget>
#include "ui_ftp_upload.h"
#include <QFtp>

class ftp_upload : public QWidget
{
	Q_OBJECT

public:
	ftp_upload(QWidget *parent = 0, Qt::WFlags flags = 0);
	~ftp_upload();
	private slots:
		void upload();

		void ftpCommandStarted(int);
		void ftpCommandFinished(int,bool);


private:
	QFtp *ftp;
	Ui::ftp_uploadClass ui;
};

#endif // FTP_UPLOAD_H
