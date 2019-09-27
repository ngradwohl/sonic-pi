#include "sessionwidget.h"
#include <QTabWidget>
#include <QTabBar>
#include "widgets/sonicpiscintilla.h"

SessionWidget::SessionWidget( QWidget *parent ) {
    // Window layout
    tabs = new QTabWidget();
    tabs->setTabsClosable(false);
    tabs->setMovable(false);
    tabs->setTabPosition(QTabWidget::South);
}

SessionWidget::~SessionWidget() {
}

void SessionWidget::addWorkspace( SonicPiScintilla *workspace, QString tabname ) {
    tabs->addTab(workspace, tabname);
}

SonicPiScintilla* SessionWidget::getCurrentWorkspace() {
    SonicPiScintilla *ws = (SonicPiScintilla*)tabs->currentWidget();
    return ws;
}

SonicPiScintilla* SessionWidget::getWorkspace( int idx ) {
    SonicPiScintilla *ws = (SonicPiScintilla *)tabs->widget( idx );
    return ws;
}

SonicPiScintilla* SessionWidget::getWorkspaceByFilename( std::string filename ) {
    for(int i=0; i < tabs->count(); i++){
        SonicPiScintilla *ws = (SonicPiScintilla *)tabs->widget(i);
        std::string s = ws->fileName.toStdString();

        if(filename == s) {
            return ws;
        }
    }
    return getWorkspace(0);
}

void SessionWidget::changeTab( int idx ) {
    tabs->setCurrentIndex( idx );
}

void SessionWidget::nextTab() {
    int index = tabs->currentIndex();
    if (index == tabs->count()-1)
        index = 0;
    else
        index++;
    QMetaObject::invokeMethod(tabs, "setCurrentIndex", Q_ARG(int, index));
}

void SessionWidget::prevTab() {
    int index = tabs->currentIndex();
    if (index == 0)
        index = tabs->count() - 1;
    else
        index--;
    QMetaObject::invokeMethod(tabs, "setCurrentIndex", Q_ARG(int, index));

}

void SessionWidget::showTabs( bool visibility ) {
    QTabBar *bar = tabs->findChild<QTabBar *>();
    if (visibility) {
        bar->show();
    } else {
        bar->hide();
    }
}
