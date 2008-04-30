#ifndef MOUNTTEXTPRIVATE_H
#define MOUNTTEXTPRIVATE_H

#include "mimedataeditor.h"

class QAbstractTextDocumentLayout;

class MountTextPrivate : public Layoutpainter
{
     Q_OBJECT
//
public:
  MountTextPrivate( QObject *parent  = 0 );
  void setContent(Qt::TextFormat format = Qt::RichText , QString text = QString() , QTextDocument *document = 0);
  void setDocument(QTextDocument *document);
  void ImageonCursor( QString file );
  QMenu *StandardMenu( QWidget * inparent );
  QTextCursor _cForPosition();
  void setxhtml( QString html );
  QTextLine currentTextLine(const QTextCursor &cursor);
  QTextLine TextLineAt(int position);
  int LinefromPosition(int position);
  QRectF Rect2cursorpoint( const QTextCursor &cursor  , const int first , const int second );
  QRectF boundingRect() const;
  void wake_up( const int msec );
  QRectF actualcursorrect();
  inline QPointF controlOffset() { return QPointF(0., boundingRect().height()); }
  void procesevent( QEvent *e );
  void paint_doc( QPainter * painter , const QStyleOptionGraphicsItem *option , QBrush BGpage , const QRectF fulllayer ,  bool alternate = false );
  void edit( bool e = false);
  inline bool editable() { return edit_enable; }
  /* ############# core doc #####################*/
  QRectF lastrect;
  //////QTextCursor C_cursor;
  /////QTextDocument *_d;
  qreal X_Pos_Cursor;
  qreal Y_Pos_Cursor;
  QAbstractTextDocumentLayout *_layout_1;
  int cursor_position;
  int position_selection_start;  /* anchor cursor */
  QRectF line_rect;
  
  int line_nummer;
  int StartSelectionMouse;
  qreal linehight;
  QTextLine DDline;
  QLineF CursorDrawLine;
  QClipboard *clipboard;
   /* ############# core doc #####################*/
  
  
uint timeline;
uint paintline;
bool cursortime;
bool movecursor;
bool cursorOn;
bool cursorIsFocusIndicator;
bool edit_enable;
bool navigatelink;
bool overwriteMode;
QMap<QString,SPics> imagemaps;
bool Cursor_From_Event_Source;

/* ############# mouse selection  doc #####################*/
QRectF FocusSelectionHighlight;
QRectF TextHighlightSelect;
QMap<int,QRectF> selection_list;
/* ############# mouse selection  doc #####################*/
void RegisterImage( SPics e , bool insert = true );  /* insert on doc default true */
int cursorWidth;
int preeditCursor;
qreal cw;  /* space font metrich widht */
protected:
  QSettings setter;
  void selectionChanged(bool forceEmitSelectionChanged = false );
  void GrepCursorData();
  bool cursorMoveKeyEvent(QKeyEvent *e);
  void setBlinkingCursorEnabled(bool enable);
  int hitTest(const QPointF &point, Qt::HitTestAccuracy accuracy) const;
  void setCursorPosition(const QPointF &pos);
  void UpadateCursor( const int freezeon );
  void repaintOldAndNewSelection(const QTextCursor &oldSelection); /* prepare paint to highlight selection text! */
  QBasicTimer cursorTimeLine;
  void tmousePressEvent(Qt::MouseButton button, const QPointF &pos, Qt::KeyboardModifiers modifiers,
                                          Qt::MouseButtons buttons, const QPoint &globalPos);
  void tmouseDoubleClickEvent(QEvent *e, Qt::MouseButton button, const QPointF &pos);
  void tmouseReleaseEvent(QEvent *e, Qt::MouseButton button, const QPointF &pos);
  void tmouseMoveEvent(QEvent *e, Qt::MouseButton button, const QPointF &pos);
  void tkeyPressEvent(QKeyEvent *e);
  void timerEvent(QTimerEvent *event);
  void repaintCursor( bool allrect = false );
  QTextCharFormat LastCharFormat;
  QRectF cursorRect(const QTextCursor &cursor);
  QRectF rectForPosition(int position);
QObject *server;

/* internal function document cursor  1 */
QMimeData *MountTextPrivate::createMimeDataFromSelection() const;
void insertFromMimeData(const QMimeData *source);
/* internal function document cursor  2 */


signals:
    void docselectionChanged();
    void cursor_newPos();
private slots:
 void update();
 void cursorPosition( const QTextCursor curs );
 void blockCount( int bb );
 void copy();
 void cut();
 void setClipboardSelection();
 void paste();
 void selectAll();
 void ClearSelections();
 void DocsizeChanged( const QSizeF size );
public slots:
 void int_clipboard_new();
 void SetLayerMargin();
 void undo();
 void redo();
 void InsertImageonCursor();
 void deleteSelected();
 void undoAvailable( bool e );
 void redoAvailable( bool e );
 

};
//
#endif // MOUNTTEXTPRIVATE_H

