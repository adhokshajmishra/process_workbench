/*
 * Process Analyzer is a small tool to analyze processes on standard LINUX
 * platform.
 *
 * Copyright (c) Adhokshaj Mishra, Swen Kooij
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>

#include <unistd.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (getuid())
    {
        QMessageBox mbox;
        mbox.setText("Root privilege required!");
        mbox.setInformativeText("This tool requires root access to report internal details"
                                " (like stack traces, memory maps, modules etc.)"
                                "\n\n Basic process details don't require root access.");

        mbox.setStandardButtons(QMessageBox::Abort | QMessageBox::Ignore);
        mbox.setDefaultButton(QMessageBox::Ignore);

        int ret = mbox.exec();

        if (ret == QMessageBox::Abort)
        {
            exit(-1);
        }
    }

    MainWindow w;
    w.show();

    return a.exec();
}
