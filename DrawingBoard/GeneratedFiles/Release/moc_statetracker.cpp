/****************************************************************************
** Meta object code from reading C++ file 'statetracker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../canvas/statetracker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'statetracker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_canvas__StateTracker_t {
    QByteArrayData data[20];
    char stringdata0[262];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_canvas__StateTracker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_canvas__StateTracker_t qt_meta_stringdata_canvas__StateTracker = {
    {
QT_MOC_LITERAL(0, 0, 20), // "canvas::StateTracker"
QT_MOC_LITERAL(1, 21, 19), // "myAnnotationCreated"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 2), // "id"
QT_MOC_LITERAL(4, 45, 22), // "layerAutoselectRequest"
QT_MOC_LITERAL(5, 68, 17), // "userMarkerAttribs"
QT_MOC_LITERAL(6, 86, 5), // "color"
QT_MOC_LITERAL(7, 92, 5), // "layer"
QT_MOC_LITERAL(8, 98, 14), // "userMarkerMove"
QT_MOC_LITERAL(9, 113, 5), // "point"
QT_MOC_LITERAL(10, 119, 5), // "trail"
QT_MOC_LITERAL(11, 125, 14), // "userMarkerHide"
QT_MOC_LITERAL(12, 140, 15), // "catchupProgress"
QT_MOC_LITERAL(13, 156, 7), // "percent"
QT_MOC_LITERAL(14, 164, 13), // "sequencePoint"
QT_MOC_LITERAL(15, 178, 19), // "previewLayerOpacity"
QT_MOC_LITERAL(16, 198, 7), // "opacity"
QT_MOC_LITERAL(17, 206, 25), // "setLocalDrawingInProgress"
QT_MOC_LITERAL(18, 232, 7), // "pendown"
QT_MOC_LITERAL(19, 240, 21) // "processQueuedCommands"

    },
    "canvas::StateTracker\0myAnnotationCreated\0"
    "\0id\0layerAutoselectRequest\0userMarkerAttribs\0"
    "color\0layer\0userMarkerMove\0point\0trail\0"
    "userMarkerHide\0catchupProgress\0percent\0"
    "sequencePoint\0previewLayerOpacity\0"
    "opacity\0setLocalDrawingInProgress\0"
    "pendown\0processQueuedCommands"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_canvas__StateTracker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       5,    3,   70,    2, 0x06 /* Public */,
       8,    3,   77,    2, 0x06 /* Public */,
      11,    1,   84,    2, 0x06 /* Public */,
      12,    1,   87,    2, 0x06 /* Public */,
      14,    1,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    2,   93,    2, 0x0a /* Public */,
      17,    1,   98,    2, 0x0a /* Public */,
      19,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QColor, QMetaType::QString,    3,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QPointF, QMetaType::Int,    3,    9,   10,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Float,    3,   16,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,

       0        // eod
};

void canvas::StateTracker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StateTracker *_t = static_cast<StateTracker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->myAnnotationCreated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->layerAutoselectRequest((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->userMarkerAttribs((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QColor(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 3: _t->userMarkerMove((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPointF(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->userMarkerHide((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->catchupProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->sequencePoint((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->previewLayerOpacity((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 8: _t->setLocalDrawingInProgress((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->processQueuedCommands(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (StateTracker::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StateTracker::myAnnotationCreated)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (StateTracker::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StateTracker::layerAutoselectRequest)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (StateTracker::*_t)(int , const QColor & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StateTracker::userMarkerAttribs)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (StateTracker::*_t)(int , const QPointF & , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StateTracker::userMarkerMove)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (StateTracker::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StateTracker::userMarkerHide)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (StateTracker::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StateTracker::catchupProgress)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (StateTracker::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StateTracker::sequencePoint)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject canvas::StateTracker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_canvas__StateTracker.data,
      qt_meta_data_canvas__StateTracker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *canvas::StateTracker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *canvas::StateTracker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_canvas__StateTracker.stringdata0))
        return static_cast<void*>(const_cast< StateTracker*>(this));
    return QObject::qt_metacast(_clname);
}

int canvas::StateTracker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void canvas::StateTracker::myAnnotationCreated(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void canvas::StateTracker::layerAutoselectRequest(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void canvas::StateTracker::userMarkerAttribs(int _t1, const QColor & _t2, const QString & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void canvas::StateTracker::userMarkerMove(int _t1, const QPointF & _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void canvas::StateTracker::userMarkerHide(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void canvas::StateTracker::catchupProgress(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void canvas::StateTracker::sequencePoint(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
