#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QDragEnterEvent>
#include <QDropEvent>
#include <QTextEdit>
#include <QScrollBar>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "imgConverter.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);

signals:
    void ConvertOrder();
    void OnDropFile(QStringList dropFileList);

public slots:
    void BrowseFile();
    void DropFile(QStringList dropFileList);
    void BrowseOutputDir();
    void OnConvertStart();
    void ProgressBar();

private:
    Ui::MainWindow *ui;
    QGraphicsScene _preview;
    void PreviewImage(QString filePath);
    QImage _previewImage;
    QStringList _nativeSeparatorPathList;
    ImgConverter* _imgConverter;
    int _convertCount = 0;
    int _progressBarCount = 0;
    void FileListControll(QStringList fileList);
};

#endif // MAINWINDOW_H
