#ifndef SESSONWIDGET_H
#define SESSONWIDGET_H

#include <QWidget>

class QTabWidget;
class SonicPiScintilla;

class SessionWidget : public QWidget
{
    Q_OBJECT

public:
    SessionWidget( QWidget *parent = 0);
    ~SessionWidget();

    void addWorkspace( SonicPiScintilla *workspace, QString tabname );
    SonicPiScintilla* getCurrentWorkspace();
    SonicPiScintilla* getWorkspace( int idx );
    SonicPiScintilla* getWorkspaceByFilename( std::string filename );
    // get code
    void changeTab( int idx );
    void showTabs( bool visibility );
    // set stylehseet
    // linenumbers
    // zoom?
    void nextTab();
    void prevTab();
    // set error marker?

private slots:
signals:
private:

    QTabWidget *tabs;

};

#endif
