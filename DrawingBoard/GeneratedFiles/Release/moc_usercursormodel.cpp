/****************************************************************************
** Meta object code from reading C++ file 'usercursormodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../canvas/usercursormodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usercursormodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_canvas__UserCursorModel_t {
    QByteArrayData data[12];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_canvas__UserCursorModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_canvas__UserCursorModel_t qt_meta_stringdata_canvas__UserCursorModel = {
    {
QT_MOC_LITERAL(0, 0, 23), // "canvas::UserCursorModel"
QT_MOC_LITERAL(1, 24, 13), // "setCursorName"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 2), // "id"
QT_MOC_LITERAL(4, 42, 4), // "name"
QT_MOC_LITERAL(5, 47, 19), // "setCursorAttributes"
QT_MOC_LITERAL(6, 67, 5), // "color"
QT_MOC_LITERAL(7, 73, 5), // "layer"
QT_MOC_LITERAL(8, 79, 17), // "setCursorPosition"
QT_MOC_LITERAL(9, 97, 3), // "pos"
QT_MOC_LITERAL(10, 101, 10), // "hideCursor"
QT_MOC_LITERAL(11, 112, 5) // "clear"

    },
    "canvas::UserCursorModel\0setCursorName\0"
    "\0id\0name\0setCursorAttributes\0color\0"
    "layer\0setCursorPosition\0pos\0hideCursor\0"
    "clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_canvas__UserCursorModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x0a /* Public */,
       5,    3,   44,    2, 0x0a /* Public */,
       8,    2,   51,    2, 0x0a /* Public */,
      10,    1,   56,    2, 0x0a /* Public */,
      11,    0,   59,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QColor, QMetaType::QString,    3,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QPointF,    3,    9,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void canvas::UserCursorModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UserCursorModel *_t = static_cast<UserCursorModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setCursorName((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->setCursorAttributes((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QColor(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 2: _t->setCursorPosition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPointF(*)>(_a[2]))); break;
        case 3: _t->hideCursor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->clear(); break;
        default: ;
        }
    }
}

const QMetaObject canvas::UserCursorModel::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_canvas__UserCursorModel.data,
      qt_meta_data_canvas__UserCursorModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *canvas::UserCursorModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *canvas::UserCursorModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_canvas__UserCursorModel.stringdata0))
        return static_cast<void*>(const_cast< UserCursorModel*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int canvas::UserCursorModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
