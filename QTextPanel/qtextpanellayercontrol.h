#ifndef QTEXTPANELLAYERCONTROL_H
#define QTEXTPANELLAYERCONTROL_H

#include <QtGui>
#include <QtCore>
#include <QDebug>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "qtextpanellayer.h"
#include "qtextpanelmime.h"
#include "qtextpaneldata.h"
#include "qtextpanelcontrol.h"

const int TextTypeFloating = QGraphicsItem::UserType + TextFloatObjectName;

class TextMount;

class QTextPanelLayerControl : public QObject, public QGraphicsRectItem
{
	Q_OBJECT

	private:
		AbsoluteLayer *header;
		AbsoluteLayer *footer;

		QRectF lastRect;
		bool contextOpen;
		TextMount *device;
		QRectF lastUpdateRequest;
		QRectF lastVisibleRequest;

	protected:
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
		bool sceneEvent(QEvent *event);
		void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
		void mousePressEvent(QGraphicsSceneMouseEvent *event);
		void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
		void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
		void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
		void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
		void keyPressEvent(QKeyEvent * event);
		void keyReleaseEvent(QKeyEvent * event);
		void focusInEvent(QFocusEvent * event);
		void focusOutEvent(QFocusEvent * event);
		void inputMethodEvent(QInputMethodEvent * event);
		/* layer floating */
		void setupHeaderFooter();

	public:

		QTextPanelLayerControl(QGraphicsItem *parent = 0);
		~QTextPanelLayerControl();
		int type() const {return TextTypeFloating;}
		QRectF boundingRect() const;
		QString pageName();
		QTextDocument *document();
		void setDocument(const QTextDocument * document , FileHandlerType Type = FOP);
		QTextCursor textCursor();
		void changePageModel(PanelPageSize e);

	public slots:
		void sceneReload();
		void ensureVisible(const QRectF areas);
		void updateArea(const QRect areas);
		void cursorWakeUp();
		void cursorStopIt();
		void pageSizeReload();
		void appendLayer();

		/*
			void deleteSelected();
			void cut();
			void paste();
			void copy();
			void undo();
			void showhtml();
			void redo();
			void selectAll();
			void InsertImageonCursor();
		*/
};

Q_DECLARE_METATYPE(QTextPanelLayerControl *)

class TextMount: public QObject
{
	Q_OBJECT

	private:
		mutable ScribePage *device;

	public:
		TextMount();
		ScribePage *txtControl() const;
		QTextPanelLayerControl *q;
};

Q_DECLARE_METATYPE(TextMount *)

#endif // QTEXTPANELLAYERCONTROL_H
