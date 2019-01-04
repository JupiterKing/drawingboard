/****************************************************************************
** Meta object code from reading C++ file 'layerlist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../canvas/layerlist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'layerlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_canvas__LayerListModel_t {
    QByteArrayData data[13];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_canvas__LayerListModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_canvas__LayerListModel_t qt_meta_stringdata_canvas__LayerListModel = {
    {
QT_MOC_LITERAL(0, 0, 22), // "canvas::LayerListModel"
QT_MOC_LITERAL(1, 23, 15), // "layersReordered"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 12), // "layerCommand"
QT_MOC_LITERAL(4, 53, 20), // "protocol::MessagePtr"
QT_MOC_LITERAL(5, 74, 3), // "msg"
QT_MOC_LITERAL(6, 78, 19), // "layerOpacityPreview"
QT_MOC_LITERAL(7, 98, 2), // "id"
QT_MOC_LITERAL(8, 101, 7), // "opacity"
QT_MOC_LITERAL(9, 109, 14), // "updateLayerAcl"
QT_MOC_LITERAL(10, 124, 6), // "locked"
QT_MOC_LITERAL(11, 131, 14), // "QList<uint8_t>"
QT_MOC_LITERAL(12, 146, 9) // "exclusive"

    },
    "canvas::LayerListModel\0layersReordered\0"
    "\0layerCommand\0protocol::MessagePtr\0"
    "msg\0layerOpacityPreview\0id\0opacity\0"
    "updateLayerAcl\0locked\0QList<uint8_t>\0"
    "exclusive"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_canvas__LayerListModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,
       6,    2,   38,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    3,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Float,    7,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, 0x80000000 | 11,    7,   10,   12,

       0        // eod
};

void canvas::LayerListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LayerListModel *_t = static_cast<LayerListModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->layersReordered(); break;
        case 1: _t->layerCommand((*reinterpret_cast< protocol::MessagePtr(*)>(_a[1]))); break;
        case 2: _t->layerOpacityPreview((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 3: _t->updateLayerAcl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QList<uint8_t>(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LayerListModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerListModel::layersReordered)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LayerListModel::*_t)(protocol::MessagePtr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerListModel::layerCommand)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (LayerListModel::*_t)(int , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerListModel::layerOpacityPreview)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject canvas::LayerListModel::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_canvas__LayerListModel.data,
      qt_meta_data_canvas__LayerListModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *canvas::LayerListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *canvas::LayerListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_canvas__LayerListModel.stringdata0))
        return static_cast<void*>(const_cast< LayerListModel*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int canvas::LayerListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void canvas::LayerListModel::layersReordered()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void canvas::LayerListModel::layerCommand(protocol::MessagePtr _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void canvas::LayerListModel::layerOpacityPreview(int _t1, float _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_canvas__LayerMimeData_t {
    QByteArrayData data[1];
    char stringdata0[22];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_canvas__LayerMimeData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_canvas__LayerMimeData_t qt_meta_stringdata_canvas__LayerMimeData = {
    {
QT_MOC_LITERAL(0, 0, 21) // "canvas::LayerMimeData"

    },
    "canvas::LayerMimeData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_canvas__LayerMimeData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void canvas::LayerMimeData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject canvas::LayerMimeData::staticMetaObject = {
    { &QMimeData::staticMetaObject, qt_meta_stringdata_canvas__LayerMimeData.data,
      qt_meta_data_canvas__LayerMimeData,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *canvas::LayerMimeData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *canvas::LayerMimeData::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_canvas__LayerMimeData.stringdata0))
        return static_cast<void*>(const_cast< LayerMimeData*>(this));
    return QMimeData::qt_metacast(_clname);
}

int canvas::LayerMimeData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMimeData::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
