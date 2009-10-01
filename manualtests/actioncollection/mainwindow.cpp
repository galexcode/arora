/*
 * Copyright 2008 Benjamin C. Meyer <ben@meyerhome.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301  USA
 */

#include "mainwindow.h"
#include "keyboardshortcutsdialog.h"

SubWebView::SubWebView(QWidget *parent)
    : QWebView(parent)
{
    QMenu *editMenu = new QMenu("Edit", this);
    QAction *action = page()->action(QWebPage::Undo);
    action->setObjectName("edit_undo");
    editMenu->addAction(action);
    addMenu(editMenu);

    QMenu *viewMenu = new QMenu("View", this);
    QAction *reloadAction = page()->action(QWebPage::Reload);
    reloadAction->setStatusTip("Reload the current webpage");
    reloadAction->setShortcut(tr("ctrl+r"));
    reloadAction->setObjectName("view_reload");
    viewMenu->addAction(reloadAction);
    addMenu(viewMenu);
    setUrl(QUrl("http://www.google.com/"));
}

SubTextEdit::SubTextEdit(QWidget *parent)
    : QTextEdit(parent)
{
    QMenu *editMenu = new QMenu("Edit", this);
    QAction *action = new QAction("Undo", this);
    action->setObjectName("edit_undo");
    editMenu->addAction(action);
    addMenu(editMenu);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    actionManager = new ActionManager(this);
    tabWidget = new QTabWidget(this);
    setCentralWidget(tabWidget);
    tabWidget->addTab(new SubWebView, "WebView");
    tabWidget->addTab(new SubTextEdit, "TextEdit");
    connect(tabWidget, SIGNAL(currentChanged(int)),
            this, SLOT(currentChanged(int)));

    QMenu *fileMenu = new QMenu("File", this);
    QAction *action = new QAction("Quit", this);
    action->setObjectName("file_quit");
    connect(action, SIGNAL(triggered()),
            this, SLOT(close()));
    fileMenu->addAction(action);
    addMenu(fileMenu);
    addMenu(new QMenu("Edit", this));
    addMenu(new QMenu("View", this));
    addMenu(new QMenu("Bookmarks", this));

    QMenu *toolsMenu = new QMenu("Tools", this);
    QAction *a = new QAction("Configure Shortcuts", this);
    connect(a, SIGNAL(triggered()),
            this, SLOT(configureShortcuts()));
    toolsMenu->addAction(a);
    addMenu(toolsMenu);

    addMenu(new QMenu("Window", this));

    QMenu *bmenu = new QMenu("Bookmarks", this);
    bmenu->addAction("always here?");
    actionManager->setMenu(bmenu);
    setActionsAlwaysVisible(true);

    currentChanged(0);
}

void MainWindow::configureShortcuts()
{
    KeyboardShortcutsDialog dialog;
    dialog.exec();
}

void MainWindow::currentChanged(int index)
{
    if (ActionCollection *document = dynamic_cast<ActionCollection*>(tabWidget->widget(index)))
        actionManager->setDocumentActionCollection(document);
}