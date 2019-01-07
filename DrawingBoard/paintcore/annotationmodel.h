/*
  Drawpile - a collaborative drawing program.

  Copyright (C) 2015-2018 Calle Laakkonen

  Drawpile is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Drawpile is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Drawpile.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef PAINTCORE_ANNOTATION_MODEL_H
#define PAINTCORE_ANNOTATION_MODEL_H

#include <QAbstractListModel>
#include <QColor>
#include <QRect>

class QDataStream;
class QPainter;
class QImage;

namespace paintcore {

	//ע�͵Ĵ洢�ṹ
struct Annotation {
	int id;					//id��ʶ
	QString text;			//����
	QRect rect;				//����
	QColor background;		//����ɫ
	bool protect;			//�Ƿ񱣻�������Ҫ
	int valign;				//��ֱ���뷽ʽ
	int	fontsize;			//�ֺŴ�С

	enum Handle {OUTSIDE, TRANSLATE, RS_TOPLEFT, RS_TOPRIGHT, RS_BOTTOMRIGHT, RS_BOTTOMLEFT, RS_TOP, RS_RIGHT, RS_BOTTOM, RS_LEFT}; //10��handle��10�����Ƶ�
	static const int HANDLE_SIZE = 10;

	// TODO this needs to be HTML aware
	bool isEmpty() const { return text.isEmpty(); }

	void paint(QPainter *painter) const;
	void paint(QPainter *painter, const QRectF &paintrect) const;
	QImage toImage() const;

	//! Get the translation handle at the point
	Handle handleAt(const QPoint &point, qreal zoom) const; //�������ĸ����Ƶ���

	//! Adjust annotation position or size
	Handle adjustGeometry(Handle handle, const QPoint &delta);

	//! Get the ID of the user who created this annotation
	uint8_t userId() const { return id>>8; }

	//! Get the protocol flags for this annotation
	uint8_t flags() const;

	//! Get the name of the vertical-align setting
	QString valignToString() const;

	//! Get the vertical align flags from the name
	static int valignFromString(const QString &va);

	void toDataStream(QDataStream &out) const;
	static Annotation fromDataStream(QDataStream &in);
};

class AnnotationModel : public QAbstractListModel {
	Q_OBJECT
public:
	enum AnnotationRoles {   //��Ӧ struct Annotation{}����������
		// DisplayRole is used to get the text
		IdRole = Qt::UserRole + 1,
		RectRole,
		BgColorRole, // avoid clash with Qt's own BackgroundColorRole
		ProtectedRole,
		VAlignRole,
		FontsetRole  //���ִ�С
	};

	explicit AnnotationModel(QObject *parent=nullptr);

	AnnotationModel *clone(QObject *newParent=nullptr) const { return new AnnotationModel(this, newParent); }

	int rowCount(const QModelIndex &parent=QModelIndex()) const; //model���ж��������ݣ���size
	QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;

	QHash<int, QByteArray> roleNames() const;

	bool isEmpty() const { return m_annotations.isEmpty(); }

	void addAnnotation(const Annotation &annotation);  //��������
	void addAnnotation(int id, const QRect &rect);
	void addAnnotation(int id, const QRect &rect,const QString strText,int iFontsize = 16);
	void deleteAnnotation(int id);						//ɾ������
	void reshapeAnnotation(int id, const QRect &newrect); //�ı���״
	void changeAnnotation(int id, const QString &newtext, bool protect, int valign, const QColor &bgcolor);  //�ı��������

	void setAnnotations(const QList<Annotation> &list);
	QList<Annotation> getAnnotations() const { return m_annotations; }

	const Annotation *annotationAtPos(const QPoint &pos, qreal zoom) const;  //ͨ�����ȡ����ѡ�����ĸ�Annotation

	Annotation::Handle annotationHandleAt(int id, const QPoint &point, qreal zoom) const;
	Annotation::Handle annotationAdjustGeometry(int id, Annotation::Handle handle, const QPoint &delta);

	const Annotation *getById(int id) const;   //ͨ��ID��ȡAnnotation

	//! Return the IDs of annotations that have no text content
	QList<int> getEmptyIds() const;  //����û��text�İ���id�б�

	void clear();

private:
	AnnotationModel(const AnnotationModel *orig, QObject *newParent);

	int findById(int id) const;

	QList<Annotation> m_annotations; //�洢�İ���list
};

}

#endif

