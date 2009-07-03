/**
 * Copyright (c) 2009, Benjamin C. Meyer
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Benjamin Meyer nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef SEARCHLINEEDIT_H
#define SEARCHLINEEDIT_H

#include "lineedit.h"

#ifdef Q_WS_MAC

class SearchLineEdit : public QWidget
{
    Q_OBJECT

signals:
    void returnPressed();
    void textEdited(const QString &text);

public:
    SearchLineEdit(QWidget *parent = 0);

    QSize sizeHint() const;

    QString text() const;
    void setText(const QString &text);
    void selectAll();
    void setInactiveText(const QString &text);
    void clear();

    QCompleter *completer() { return 0; }
    void setCompleter(QCompleter *completer) {}

private:
    QWidget *nativeWidget;

};

#else
/*

class ClearButton;
class SearchButton;
class SearchLineEdit : public LineEdit
{
    Q_OBJECT

public:
    SearchLineEdit(QWidget *parent = 0);

    ClearButton *clearButton() const;
    SearchButton *searchButton() const;

private:
    void init();
    ClearButton *m_clearButton;
    SearchButton *m_searchButton;

};
*/
#endif

#endif // SEARCHLINEEDIT_H

