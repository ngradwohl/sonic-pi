//--
// This file is part of Sonic Pi: http://sonic-pi.net
// Full project source: https://github.com/samaaron/sonic-pi
// License: https://github.com/samaaron/sonic-pi/blob/master/LICENSE.md
//
// Copyright 2017 by Sam Aaron (http://sam.aaron.name).
// All rights reserved.
//
// Permission is granted for use, copying, modification, and
// distribution of modified versions of this work as long as this
// notice is included.
//++

#include <QCloseEvent>
#include <QBoxLayout>
#include <QTextBrowser>
#include <QTextEdit>
#include <QTabWidget>
#include <QShortcut>
#include <QKeySequence>
#include "infowidget.h"

#include <iostream>
#include "keycodes.h"

InfoWidget::InfoWidget(QWidget *parent) : QWidget(parent) {
    std::cout << "[GUI] - creating info panel" << std::endl;
    QTabWidget* infoTabs = new QTabWidget(this);

    QStringList urls, tabs;

    urls << "qrc:///html/info.html"
        << "qrc:///info/COMMUNITY.html"
        << "qrc:///info/CORETEAM.html"
        << "qrc:///info/CONTRIBUTORS.html"
        << "qrc:///info/LICENSE.html"
        << "qrc:///info/CHANGELOG.html";

    tabs << tr("About")
        << tr("Community")
        << tr("Core Team")
        << tr("Contributors")
        << tr("License")
        << tr("History");

    for (int t=0; t < urls.size(); t++) {
        QTextBrowser *pane = new QTextBrowser;
        infoPanes.append(pane);
        addUniversalCopyShortcuts(pane);
        pane->setOpenExternalLinks(true);
        pane->setSource(QUrl(urls[t]));
        infoTabs->addTab(pane, tabs[t]);
    }

    infoTabs->setTabPosition(QTabWidget::South);

    QBoxLayout *infoLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    infoLayout->addWidget(infoTabs);

    setWindowIcon(QIcon(":images/icon-smaller.png"));
    setLayout(infoLayout);
    setWindowFlags(Qt::Tool | Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);
    setWindowTitle(tr("Sonic Pi - Info"));
    setFixedSize(660, 640);
}

void InfoWidget::closeEvent(QCloseEvent *event){
  emit closed();
  event->accept();
}

void InfoWidget::setDefaultStyleSheet(QString css) {
    foreach(QTextBrowser* pane, infoPanes) {
        pane->document()->setDefaultStyleSheet(css);
        pane->reload();
    }
}

void InfoWidget::addUniversalCopyShortcuts(QTextEdit *te){
    new QShortcut(ctrlKey('c'), te, SLOT(copy()));
    new QShortcut(ctrlKey('a'), te, SLOT(selectAll()));

    new QShortcut(metaKey('c'), te, SLOT(copy()));
    new QShortcut(metaKey('a'), te, SLOT(selectAll()));
}

QKeySequence InfoWidget::ctrlKey(char key) {
    return QKeySequence(QString(SP_CTRL).arg(key));
}

QKeySequence InfoWidget::metaKey(char key) {
    return QKeySequence(QString(SP_META).arg(key));
}

