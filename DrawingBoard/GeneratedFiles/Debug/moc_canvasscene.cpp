/****************************************************************************
** Meta object code from reading C++ file 'canvasscene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../drawingboard/canvasscene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canvasscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_drawingboard__CanvasScene_t {
    QByteArrayData data[36];
    char stringdata0[486];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_drawingboard__CanvasScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_drawingboard__CanvasScene_t qt_meta_stringdata_drawingboard__CanvasScene = {
    {
QT_MOC_LITERAL(0, 0, 25), // "drawingboard::CanvasScene"
QT_MOC_LITERAL(1, 26, 13), // "canvasResized"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 7), // "xoffset"
QT_MOC_LITERAL(4, 49, 7), // "yoffset"
QT_MOC_LITERAL(5, 57, 7), // "oldSize"
QT_MOC_LITERAL(6, 65, 21), // "showAnnotationBorders"
QT_MOC_LITERAL(7, 87, 2), // "hl"
QT_MOC_LITERAL(8, 90, 15), // "showUserMarkers"
QT_MOC_LITERAL(9, 106, 4), // "show"
QT_MOC_LITERAL(10, 111, 14), // "showUserLayers"
QT_MOC_LITERAL(11, 126, 15), // "showLaserTrails"
QT_MOC_LITERAL(12, 142, 23), // "activeAnnotationChanged"
QT_MOC_LITERAL(13, 166, 2), // "id"
QT_MOC_LITERAL(14, 169, 10), // "showCanvas"
QT_MOC_LITERAL(15, 180, 10), // "hideCanvas"
QT_MOC_LITERAL(16, 191, 18), // "onSelectionChanged"
QT_MOC_LITERAL(17, 210, 24), // "canvas::canvasSelection*"
QT_MOC_LITERAL(18, 235, 3), // "sel"
QT_MOC_LITERAL(19, 239, 18), // "handleCanvasResize"
QT_MOC_LITERAL(20, 258, 7), // "oldsize"
QT_MOC_LITERAL(21, 266, 26), // "advanceUsermarkerAnimation"
QT_MOC_LITERAL(22, 293, 15), // "userCursorAdded"
QT_MOC_LITERAL(23, 309, 5), // "first"
QT_MOC_LITERAL(24, 315, 4), // "last"
QT_MOC_LITERAL(25, 320, 17), // "userCursorRemoved"
QT_MOC_LITERAL(26, 338, 17), // "userCursorChanged"
QT_MOC_LITERAL(27, 356, 12), // "QVector<int>"
QT_MOC_LITERAL(28, 369, 7), // "changed"
QT_MOC_LITERAL(29, 377, 16), // "annotationsAdded"
QT_MOC_LITERAL(30, 394, 18), // "annotationsRemoved"
QT_MOC_LITERAL(31, 413, 18), // "annotationsChanged"
QT_MOC_LITERAL(32, 432, 16), // "annotationsReset"
QT_MOC_LITERAL(33, 449, 10), // "laserAdded"
QT_MOC_LITERAL(34, 460, 12), // "laserRemoved"
QT_MOC_LITERAL(35, 473, 12) // "laserChanged"

    },
    "drawingboard::CanvasScene\0canvasResized\0"
    "\0xoffset\0yoffset\0oldSize\0showAnnotationBorders\0"
    "hl\0showUserMarkers\0show\0showUserLayers\0"
    "showLaserTrails\0activeAnnotationChanged\0"
    "id\0showCanvas\0hideCanvas\0onSelectionChanged\0"
    "canvas::canvasSelection*\0sel\0"
    "handleCanvasResize\0oldsize\0"
    "advanceUsermarkerAnimation\0userCursorAdded\0"
    "first\0last\0userCursorRemoved\0"
    "userCursorChanged\0QVector<int>\0changed\0"
    "annotationsAdded\0annotationsRemoved\0"
    "annotationsChanged\0annotationsReset\0"
    "laserAdded\0laserRemoved\0laserChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_drawingboard__CanvasScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,  119,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,  126,    2, 0x0a /* Public */,
       8,    1,  129,    2, 0x0a /* Public */,
      10,    1,  132,    2, 0x0a /* Public */,
      11,    1,  135,    2, 0x0a /* Public */,
      12,    1,  138,    2, 0x0a /* Public */,
      14,    0,  141,    2, 0x0a /* Public */,
      15,    0,  142,    2, 0x0a /* Public */,
      16,    1,  143,    2, 0x08 /* Private */,
      19,    3,  146,    2, 0x08 /* Private */,
      21,    0,  153,    2, 0x08 /* Private */,
      22,    3,  154,    2, 0x08 /* Private */,
      25,    3,  161,    2, 0x08 /* Private */,
      26,    3,  168,    2, 0x08 /* Private */,
      29,    3,  175,    2, 0x08 /* Private */,
      30,    3,  182,    2, 0x08 /* Private */,
      31,    3,  189,    2, 0x08 /* Private */,
      32,    0,  196,    2, 0x08 /* Private */,
      33,    3,  197,    2, 0x08 /* Private */,
      34,    3,  204,    2, 0x08 /* Private */,
      35,    3,  211,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QSize,    3,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QSize,    3,    4,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    2,   23,   24,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    2,   23,   24,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex, 0x80000000 | 27,   23,   24,   28,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    2,   23,   24,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    2,   23,   24,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex, 0x80000000 | 27,   23,   24,   28,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    2,   23,   24,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    2,   23,   24,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex, 0x80000000 | 27,   23,   24,   28,

       0        // eod
};

void drawingboard::CanvasScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CanvasScene *_t = static_cast<CanvasScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->canvasResized((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QSize(*)>(_a[3]))); break;
        case 1: _t->showAnnotationBorders((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->showUserMarkers((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->showUserLayers((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->showLaserTrails((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->activeAnnotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->showCanvas(); break;
        case 7: _t->hideCanvas(); break;
        case 8: _t->onSelectionChanged((*reinterpret_cast< canvas::canvasSelection*(*)>(_a[1]))); break;
        case 9: _t->handleCanvasResize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QSize(*)>(_a[3]))); break;
        case 10: _t->advanceUsermarkerAnimation(); break;
        case 11: _t->userCursorAdded((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 12: _t->userCursorRemoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 13: _t->userCursorChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2])),(*reinterpret_cast< const QVector<int>(*)>(_a[3]))); break;
        case 14: _t->annotationsAdded((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 15: _t->annotationsRemoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 16: _t->annotationsChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2])),(*reinterpret_cast< const QVector<int>(*)>(_a[3]))); break;
        case 17: _t->annotationsReset(); break;
        case 18: _t->laserAdded((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 19: _t->laserRemoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 20: _t->laserChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2])),(*reinterpret_cast< const QVector<int>(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CanvasScene::*_t)(int , int , const QSize & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CanvasScene::canvasResized)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject drawingboard::CanvasScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_drawingboard__CanvasScene.data,
      qt_meta_data_drawingboard__CanvasScene,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *drawingboard::CanvasScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *drawingboard::CanvasScene::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_drawingboard__CanvasScene.stringdata0))
        return static_cast<void*>(const_cast< CanvasScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int drawingboard::CanvasScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void drawingboard::CanvasScene::canvasResized(int _t1, int _t2, const QSize & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
