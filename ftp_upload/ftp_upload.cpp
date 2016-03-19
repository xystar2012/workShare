#include "ftp_upload.h"
#include <QFile>

ftp_upload::ftp_upload(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);
	ftp = NULL;
	connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(upload()));
}

ftp_upload::~ftp_upload()
{
	if(ftp != NULL)
		ftp->close();   //关闭连接
}

void ftp_upload::upload()
{
	ftp = new QFtp(this);
    ftp->connectToHost("192.168.0.50",21); //连接到服务器
    ftp->login("test","testpassword");   //登录


//windows自带的ftp服务器，文件上传
	QFile *uploadFile = new QFile("D:/2014.txt");
	QString des = "2014_uploadToServer.txt";
	uploadFile->open(QIODevice::ReadWrite);
	ftp->put(uploadFile,des);


//windows自带的ftp服务器，文件下载
	QFile *download = new QFile("D:/downloadFromServer.txt");
	download->open(QIODevice::ReadWrite);
	ftp->get("download.txt",download);//把服务器物理路径根目录下的download.txt下载到本地D盘根目录


	connect(ftp,SIGNAL(commandStarted(int)),this,SLOT(ftpCommandStarted(int)));

    //当每条命令开始执行时发出相应的信号
	connect(ftp,SIGNAL(commandFinished(int,bool)),this,SLOT(ftpCommandFinished(int,bool)));
}

void ftp_upload::ftpCommandStarted(int)
{
    if(ftp->currentCommand() == QFtp::ConnectToHost){
        ui.label->setText(tr("正在连接到服务器…"));
    }
    if (ftp->currentCommand() == QFtp::Login){
        ui.label->setText(tr("正在登录…"));
    }
    if (ftp->currentCommand() == QFtp::Get){
        ui.label->setText(tr("正在下载…"));
    }
    else if (ftp->currentCommand() == QFtp::Close){
        ui.label->setText(tr("正在关闭连接…"));
    }
}


void ftp_upload::ftpCommandFinished(int,bool error)
{
    if(ftp->currentCommand() == QFtp::ConnectToHost){
        if(error)
			ui.label->setText(tr("连接服务器出现错误:%1").arg(ftp->errorString() ));
        else
			ui.label->setText(tr("连接到服务器成功"));
    }
    if (ftp->currentCommand() == QFtp::Login){
        if(error)
			ui.label->setText(tr("登录出现错误:%1").arg(ftp->errorString()));
        else 
		{
			ui.label->setText(tr("登录成功"));
		}
    }
    if (ftp->currentCommand() == QFtp::Put){
        if(error)
		{
			ui.label->setText(tr("上传出现错误:%1").arg(ftp->errorString()));
			ui.textEdit->setText(tr("上传出现错误:%1").arg(ftp->errorString()));
		}
			
        else {
            ui.label->setText(tr("已经完成上传"));
        }
    }
	if (ftp->currentCommand() == QFtp::Get){
        if(error)
		{
			ui.textEdit->setText(tr("下载出现错误:%1").arg(ftp->errorString()));
		}
        else {
            ui.label->setText(tr("已经完成下载"));
        }
    }
    else if (ftp->currentCommand() == QFtp::Close){
        ui.label->setText(tr("已经关闭连接"));
    }
}

