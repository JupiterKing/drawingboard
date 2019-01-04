/****************************************************************************
** Meta object code from reading C++ file 'canvasSelection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../canvas/canvasSelection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canvasSelection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_canvas__canvasSelection_t {
    QByteArrayData data[16];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_canvas__canvasSelection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_canvas__canvasSelection_t qt_meta_stringdata_canvas__canvasSelection = {
    {
QT_MOC_LITERAL(0, 0, 23), // "canvas::canvasSelection"
QT_MOC_LITERAL(1, 24, 12), // "shapeChanged"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 5), // "shape"
QT_MOC_LITERAL(4, 44, 17), // "pasteImageChanged"
QT_MOC_LITERAL(5, 62, 5), // "image"
QT_MOC_LITERAL(6, 68, 6), // "closed"
QT_MOC_LITERAL(7, 75, 10), // "resetShape"
QT_MOC_LITERAL(8, 86, 5), // "reset"
QT_MOC_LITERAL(9, 92, 9), // "translate"
QT_MOC_LITERAL(10, 102, 6), // "offset"
QT_MOC_LITERAL(11, 109, 5), // "scale"
QT_MOC_LITERAL(12, 115, 1), // "x"
QT_MOC_LITERAL(13, 117, 1), // "y"
QT_MOC_LITERAL(14, 119, 10), // "pasteImage"
QT_MOC_LITERAL(15, 130, 10) // "handleSize"

    },
    "canvas::canvasSelection\0shapeChanged\0"
    "\0shape\0pasteImageChanged\0image\0closed\0"
    "resetShape\0reset\0translate\0offset\0"
    "scale\0x\0y\0pasteImage\0handleSize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_canvas__canvasSelection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       3,   66, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       6,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   56,    2, 0x0a /* Public */,
       8,    0,   57,    2, 0x0a /* Public */,
       9,    1,   58,    2, 0x0a /* Public */,
      11,    2,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPolygonF,    3,
    QMetaType::Void, QMetaType::QImage,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   10,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,   12,   13,

 // properties: name, type, flags
       3, QMetaType::QPolygonF, 0x00495103,
      14, QMetaType::QImage, 0x00495103,
      15, QMetaType::Int, 0x00095401,

 // properties: notify_signal_id
       0,
       1,
       0,

       0        // eod
};

void canvas::canvasSelection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        canvasSelection *_t = static_cast<canvasSelection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->shapeChanged((*reinterpret_cast< const QPolygonF(*)>(_a[1]))); break;
        case 1: _t->pasteImageChanged((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 2: _t->closed(); break;
        case 3: _t->resetShape(); break;
        case 4: _t->reset(); break;
        case 5: _t->translate((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 6: _t->scale((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (canvasSelection::*_t)(const QPolygonF & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&canvasSelection::shapeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (canvasSelection::*_t)(const QImage & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&canvasSelection::pasteImageChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (canvasSelection::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&canvasSelection::closed)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Q_ASSERT(staticMetaObject.cast(_o));
        canvasSelection *_t = static_cast<canvasSelection *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QPolygonF*>(_v) = _t->shape(); break;
        case 1: *reinterpret_cast< QImage*>(_v) = _t->pasteImage(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->handleSize(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Q_ASSERT(staticMetaObject.cast(_o));
        canvasSelection *_t = static_cast<canvasSelection *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setShape(*reinterpret_cast< QPolygonF*>(_v)); break;
        case 1: _t->setPasteImage(*reinterpret_cast< QImage*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject canvas::canvasSelection::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_canvas__canvasSelection.data,
      qt_meta_data_canvas__canvasSelection,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *canvas::canvasSelection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *canvas::canvasSelection::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_canvas__canvasSelection.stringdata0))
        return static_cast<void*>(const_cast< canvasSelection*>(this));
    return QObject::qt_metacast(_clname);
}

int canvas::canvasSelection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void canvas::canvasSelection::shapeChanged(const QPolygonF & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void canvas::canvasSelection::pasteImageChanged(const QImage & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void canvas::canvasSelection::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
