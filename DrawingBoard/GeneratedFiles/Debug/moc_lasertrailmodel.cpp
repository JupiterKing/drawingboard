/****************************************************************************
** Meta object code from reading C++ file 'lasertrailmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../canvas/lasertrailmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lasertrailmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_canvas__LaserTrailModel_t {
    QByteArrayData data[9];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_canvas__LaserTrailModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_canvas__LaserTrailModel_t qt_meta_stringdata_canvas__LaserTrailModel = {
    {
QT_MOC_LITERAL(0, 0, 23), // "canvas::LaserTrailModel"
QT_MOC_LITERAL(1, 24, 10), // "startTrail"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 5), // "ctxId"
QT_MOC_LITERAL(4, 42, 5), // "color"
QT_MOC_LITERAL(5, 48, 11), // "persistence"
QT_MOC_LITERAL(6, 60, 8), // "addPoint"
QT_MOC_LITERAL(7, 69, 5), // "point"
QT_MOC_LITERAL(8, 75, 8) // "endTrail"

    },
    "canvas::LaserTrailModel\0startTrail\0\0"
    "ctxId\0color\0persistence\0addPoint\0point\0"
    "endTrail"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_canvas__LaserTrailModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x0a /* Public */,
       6,    2,   36,    2, 0x0a /* Public */,
       8,    1,   41,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QColor, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QPointF,    3,    7,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void canvas::LaserTrailModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LaserTrailModel *_t = static_cast<LaserTrailModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startTrail((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QColor(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->addPoint((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPointF(*)>(_a[2]))); break;
        case 2: _t->endTrail((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject canvas::LaserTrailModel::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_canvas__LaserTrailModel.data,
      qt_meta_data_canvas__LaserTrailModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *canvas::LaserTrailModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *canvas::LaserTrailModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_canvas__LaserTrailModel.stringdata0))
        return static_cast<void*>(const_cast< LaserTrailModel*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int canvas::LaserTrailModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
