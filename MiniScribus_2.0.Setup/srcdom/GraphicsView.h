/*******************************************************************************
 * class GraphicsView
 *******************************************************************************
 * Copyright (C) 2007 by Peter Hohl
 * e-Mail: ppkciz@gmail.com
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *******************************************************************************/

#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H
#include <iostream>
#include <stdio.h>
#include <iostream>
#include <QtCore>
#include <QDebug>
#include <QCoreApplication>
#include <QObject>
#include <QGraphicsView>
#include "GraphicsItemEdit.h"
#include "mounttextprivate.h"
#include "GraphicsScene.h"
#include <math.h>

class GraphicsView : public QGraphicsView
{
     Q_OBJECT
//
public:
  GraphicsView( QWidget * parent  = 0 );
  TextLayer *CurrentActive;
  QRectF boundingRect();
protected:
    QSettings setter;
    void resizeEvent(QResizeEvent *event);
    void wheelEvent (QWheelEvent * event);
    void drawBackground(QPainter *painter, const QRectF &rect);
    void scaleView (qreal scaleFactor);
  GraphicsScene *scene;
  qreal width;
  qreal height;
  uint layercount;
  QWidget *BigParent;
  QPixmap chessgrid;
private:
  void fillNullItem();
signals:
   void active_items(bool);
public slots:
    void AppendDemo();
    void WorksOn(QGraphicsItem * item , qreal zindex );
    void notselect();
    void DisplayTop();
    void sceneScaleChanged(const QString &scale);
    void GoEditCurrentLayer();

};
//
#endif // GRAPHICSVIEW_H
