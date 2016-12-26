// lwlogger.h
//
// lwlogger(8) LiveWire routing daemon
//
//   (C) Copyright 2016 Fred Gleason <fredg@paravelsystems.com>
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as
//   published by the Free Software Foundation; either version 2 of
//   the License, or (at your option) any later version.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public
//   License along with this program; if not, write to the Free Software
//   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//

#ifndef LWLOGGER_H
#define LWLOGGER_H

#include <QObject>

#include <sy/sygpio_server.h>

#include "config.h"

#define LWLOGGER_USAGE "[options]\n"

class MainObject : public QObject
{
 Q_OBJECT;
 public:
  MainObject(QObject *parent=0);

 private slots:
  void  gpioReceivedData(SyGpioEvent *e);

 private:
  void Log(const QString &dirname,const QString &msg) const;
  SyGpioServer *main_gpio_server;
  Config *main_config;
};


#endif  // LWLOGGER_H
