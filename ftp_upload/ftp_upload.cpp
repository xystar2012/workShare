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
		ftp->close();   //�ر�����
}

void ftp_upload::upload()
{
	ftp = new QFtp(this);
    ftp->connectToHost("192.168.0.50",21); //���ӵ�������
    ftp->login("test","testpassword");   //��¼


//windows�Դ���ftp���������ļ��ϴ�
	QFile *uploadFile = new QFile("D:/2014.txt");
	QString des = "2014_uploadToServer.txt";
	uploadFile->open(QIODevice::ReadWrite);
	ftp->put(uploadFile,des);


//windows�Դ���ftp���������ļ�����
	QFile *download = new QFile("D:/downloadFromServer.txt");
	download->open(QIODevice::ReadWrite);
	ftp->get("download.txt",download);//�ѷ���������·����Ŀ¼�µ�download.txt���ص�����D�̸�Ŀ¼


	connect(ftp,SIGNAL(commandStarted(int)),this,SLOT(ftpCommandStarted(int)));

    //��ÿ�����ʼִ��ʱ������Ӧ���ź�
	connect(ftp,SIGNAL(commandFinished(int,bool)),this,SLOT(ftpCommandFinished(int,bool)));
}

void ftp_upload::ftpCommandStarted(int)
{
    if(ftp->currentCommand() == QFtp::ConnectToHost){
        ui.label->setText(tr("�������ӵ���������"));
    }
    if (ftp->currentCommand() == QFtp::Login){
        ui.label->setText(tr("���ڵ�¼��"));
    }
    if (ftp->currentCommand() == QFtp::Get){
        ui.label->setText(tr("�������ء�"));
    }
    else if (ftp->currentCommand() == QFtp::Close){
        ui.label->setText(tr("���ڹر����ӡ�"));
    }
}


void ftp_upload::ftpCommandFinished(int,bool error)
{
    if(ftp->currentCommand() == QFtp::ConnectToHost){
        if(error)
			ui.label->setText(tr("���ӷ��������ִ���:%1").arg(ftp->errorString() ));
        else
			ui.label->setText(tr("���ӵ��������ɹ�"));
    }
    if (ftp->currentCommand() == QFtp::Login){
        if(error)
			ui.label->setText(tr("��¼���ִ���:%1").arg(ftp->errorString()));
        else 
		{
			ui.label->setText(tr("��¼�ɹ�"));
		}
    }
    if (ftp->currentCommand() == QFtp::Put){
        if(error)
		{
			ui.label->setText(tr("�ϴ����ִ���:%1").arg(ftp->errorString()));
			ui.textEdit->setText(tr("�ϴ����ִ���:%1").arg(ftp->errorString()));
		}
			
        else {
            ui.label->setText(tr("�Ѿ�����ϴ�"));
        }
    }
	if (ftp->currentCommand() == QFtp::Get){
        if(error)
		{
			ui.textEdit->setText(tr("���س��ִ���:%1").arg(ftp->errorString()));
		}
        else {
            ui.label->setText(tr("�Ѿ��������"));
        }
    }
    else if (ftp->currentCommand() == QFtp::Close){
        ui.label->setText(tr("�Ѿ��ر�����"));
    }
}

