/****************************************************************************
** Meta object code from reading C++ file 'toolcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tools/toolcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toolcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_tools__ToolController_t {
    QByteArrayData data[50];
    char stringdata0[653];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tools__ToolController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tools__ToolController_t qt_meta_stringdata_tools__ToolController = {
    {
QT_MOC_LITERAL(0, 0, 21), // "tools::ToolController"
QT_MOC_LITERAL(1, 22, 17), // "activeToolChanged"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 10), // "Tool::Type"
QT_MOC_LITERAL(4, 52, 4), // "type"
QT_MOC_LITERAL(5, 57, 17), // "toolCursorChanged"
QT_MOC_LITERAL(6, 75, 6), // "cursor"
QT_MOC_LITERAL(7, 82, 18), // "activeLayerChanged"
QT_MOC_LITERAL(8, 101, 7), // "layerId"
QT_MOC_LITERAL(9, 109, 23), // "activeAnnotationChanged"
QT_MOC_LITERAL(10, 133, 12), // "annotationId"
QT_MOC_LITERAL(11, 146, 18), // "activeBrushChanged"
QT_MOC_LITERAL(12, 165, 16), // "paintcore::Brush"
QT_MOC_LITERAL(13, 182, 12), // "modelChanged"
QT_MOC_LITERAL(14, 195, 20), // "canvas::CanvasModel*"
QT_MOC_LITERAL(15, 216, 5), // "model"
QT_MOC_LITERAL(16, 222, 16), // "smoothingChanged"
QT_MOC_LITERAL(17, 239, 9), // "smoothing"
QT_MOC_LITERAL(18, 249, 15), // "messageReceived"
QT_MOC_LITERAL(19, 265, 20), // "protocol::MessagePtr"
QT_MOC_LITERAL(20, 286, 3), // "msg"
QT_MOC_LITERAL(21, 290, 19), // "drawingCommandLocal"
QT_MOC_LITERAL(22, 310, 15), // "sentColorChange"
QT_MOC_LITERAL(23, 326, 5), // "color"
QT_MOC_LITERAL(24, 332, 10), // "setDotline"
QT_MOC_LITERAL(25, 343, 4), // "bDot"
QT_MOC_LITERAL(26, 348, 11), // "sendMessage"
QT_MOC_LITERAL(27, 360, 12), // "sendMessages"
QT_MOC_LITERAL(28, 373, 27), // "QList<protocol::MessagePtr>"
QT_MOC_LITERAL(29, 401, 4), // "msgs"
QT_MOC_LITERAL(30, 406, 12), // "startDrawing"
QT_MOC_LITERAL(31, 419, 5), // "point"
QT_MOC_LITERAL(32, 425, 8), // "pressure"
QT_MOC_LITERAL(33, 434, 5), // "right"
QT_MOC_LITERAL(34, 440, 4), // "zoom"
QT_MOC_LITERAL(35, 445, 15), // "continueDrawing"
QT_MOC_LITERAL(36, 461, 5), // "shift"
QT_MOC_LITERAL(37, 467, 3), // "alt"
QT_MOC_LITERAL(38, 471, 12), // "hoverDrawing"
QT_MOC_LITERAL(39, 484, 10), // "endDrawing"
QT_MOC_LITERAL(40, 495, 20), // "undoMultipartDrawing"
QT_MOC_LITERAL(41, 516, 22), // "finishMultipartDrawing"
QT_MOC_LITERAL(42, 539, 22), // "cancelMultipartDrawing"
QT_MOC_LITERAL(43, 562, 21), // "onAnnotationRowDelete"
QT_MOC_LITERAL(44, 584, 5), // "first"
QT_MOC_LITERAL(45, 590, 4), // "last"
QT_MOC_LITERAL(46, 595, 16), // "activeToolCursor"
QT_MOC_LITERAL(47, 612, 11), // "activeLayer"
QT_MOC_LITERAL(48, 624, 16), // "activeAnnotation"
QT_MOC_LITERAL(49, 641, 11) // "activeBrush"

    },
    "tools::ToolController\0activeToolChanged\0"
    "\0Tool::Type\0type\0toolCursorChanged\0"
    "cursor\0activeLayerChanged\0layerId\0"
    "activeAnnotationChanged\0annotationId\0"
    "activeBrushChanged\0paintcore::Brush\0"
    "modelChanged\0canvas::CanvasModel*\0"
    "model\0smoothingChanged\0smoothing\0"
    "messageReceived\0protocol::MessagePtr\0"
    "msg\0drawingCommandLocal\0sentColorChange\0"
    "color\0setDotline\0bDot\0sendMessage\0"
    "sendMessages\0QList<protocol::MessagePtr>\0"
    "msgs\0startDrawing\0point\0pressure\0right\0"
    "zoom\0continueDrawing\0shift\0alt\0"
    "hoverDrawing\0endDrawing\0undoMultipartDrawing\0"
    "finishMultipartDrawing\0cancelMultipartDrawing\0"
    "onAnnotationRowDelete\0first\0last\0"
    "activeToolCursor\0activeLayer\0"
    "activeAnnotation\0activeBrush"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tools__ToolController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       6,  190, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x06 /* Public */,
       5,    1,  122,    2, 0x06 /* Public */,
       7,    1,  125,    2, 0x06 /* Public */,
       9,    1,  128,    2, 0x06 /* Public */,
      11,    1,  131,    2, 0x06 /* Public */,
      13,    1,  134,    2, 0x06 /* Public */,
      16,    1,  137,    2, 0x06 /* Public */,
      18,    1,  140,    2, 0x06 /* Public */,
      21,    1,  143,    2, 0x06 /* Public */,
      22,    1,  146,    2, 0x06 /* Public */,
      24,    1,  149,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      26,    1,  152,    2, 0x0a /* Public */,
      27,    1,  155,    2, 0x0a /* Public */,
      30,    4,  158,    2, 0x0a /* Public */,
      35,    4,  167,    2, 0x0a /* Public */,
      38,    1,  176,    2, 0x0a /* Public */,
      39,    0,  179,    2, 0x0a /* Public */,
      40,    0,  180,    2, 0x0a /* Public */,
      41,    0,  181,    2, 0x0a /* Public */,
      42,    0,  182,    2, 0x0a /* Public */,
      43,    3,  183,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QCursor,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, QMetaType::QColor,   23,
    QMetaType::Void, QMetaType::Bool,   25,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void, QMetaType::QPointF, QMetaType::QReal, QMetaType::Bool, QMetaType::Float,   31,   32,   33,   34,
    QMetaType::Void, QMetaType::QPointF, QMetaType::QReal, QMetaType::Bool, QMetaType::Bool,   31,   32,   36,   37,
    QMetaType::Void, QMetaType::QPointF,   31,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    2,   44,   45,

 // properties: name, type, flags
      46, QMetaType::QCursor, 0x00495001,
      17, QMetaType::Int, 0x00495103,
      47, QMetaType::Int, 0x00495103,
      48, QMetaType::Int, 0x00495103,
      49, 0x80000000 | 12, 0x0049510b,
      15, 0x80000000 | 14, 0x0049510b,

 // properties: notify_signal_id
       1,
       6,
       2,
       3,
       4,
       5,

       0        // eod
};

void tools::ToolController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ToolController *_t = static_cast<ToolController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->activeToolChanged((*reinterpret_cast< Tool::Type(*)>(_a[1]))); break;
        case 1: _t->toolCursorChanged((*reinterpret_cast< const QCursor(*)>(_a[1]))); break;
        case 2: _t->activeLayerChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->activeAnnotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->activeBrushChanged((*reinterpret_cast< const paintcore::Brush(*)>(_a[1]))); break;
        case 5: _t->modelChanged((*reinterpret_cast< canvas::CanvasModel*(*)>(_a[1]))); break;
        case 6: _t->smoothingChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->messageReceived((*reinterpret_cast< protocol::MessagePtr(*)>(_a[1]))); break;
        case 8: _t->drawingCommandLocal((*reinterpret_cast< protocol::MessagePtr(*)>(_a[1]))); break;
        case 9: _t->sentColorChange((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 10: _t->setDotline((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->sendMessage((*reinterpret_cast< const protocol::MessagePtr(*)>(_a[1]))); break;
        case 12: _t->sendMessages((*reinterpret_cast< const QList<protocol::MessagePtr>(*)>(_a[1]))); break;
        case 13: _t->startDrawing((*reinterpret_cast< const QPointF(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 14: _t->continueDrawing((*reinterpret_cast< const QPointF(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 15: _t->hoverDrawing((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 16: _t->endDrawing(); break;
        case 17: { bool _r = _t->undoMultipartDrawing();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 18: _t->finishMultipartDrawing(); break;
        case 19: _t->cancelMultipartDrawing(); break;
        case 20: _t->onAnnotationRowDelete((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ToolController::*_t)(Tool::Type );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolController::activeToolChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ToolController::*_t)(const QCursor & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolController::toolCursorChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ToolController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolController::activeLayerChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ToolController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolController::activeAnnotationChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ToolController::*_t)(const paintcore::Brush & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolController::activeBrushChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ToolController::*_t)(canvas::CanvasModel * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolController::modelChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (ToolController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolController::smoothingChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (ToolController::*_t)(protocol::MessagePtr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolController::messageReceived)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (ToolController::*_t)(protocol::MessagePtr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolController::drawingCommandLocal)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (ToolController::*_t)(const QColor & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolController::sentColorChange)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (ToolController::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolController::setDotline)) {
                *result = 10;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ToolController *_t = static_cast<ToolController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QCursor*>(_v) = _t->activeToolCursor(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->smoothing(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->activeLayer(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->activeAnnotation(); break;
        case 4: *reinterpret_cast< paintcore::Brush*>(_v) = _t->activeBrush(); break;
        case 5: *reinterpret_cast< canvas::CanvasModel**>(_v) = _t->model(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ToolController *_t = static_cast<ToolController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setSmoothing(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setActiveLayer(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setActiveAnnotation(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setActiveBrush(*reinterpret_cast< paintcore::Brush*>(_v)); break;
        case 5: _t->setModel(*reinterpret_cast< canvas::CanvasModel**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject tools::ToolController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_tools__ToolController.data,
      qt_meta_data_tools__ToolController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *tools::ToolController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tools::ToolController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_tools__ToolController.stringdata0))
        return static_cast<void*>(const_cast< ToolController*>(this));
    return QObject::qt_metacast(_clname);
}

int tools::ToolController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void tools::ToolController::activeToolChanged(Tool::Type _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void tools::ToolController::toolCursorChanged(const QCursor & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void tools::ToolController::activeLayerChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void tools::ToolController::activeAnnotationChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void tools::ToolController::activeBrushChanged(const paintcore::Brush & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void tools::ToolController::modelChanged(canvas::CanvasModel * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void tools::ToolController::smoothingChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void tools::ToolController::messageReceived(protocol::MessagePtr _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void tools::ToolController::drawingCommandLocal(protocol::MessagePtr _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void tools::ToolController::sentColorChange(const QColor & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void tools::ToolController::setDotline(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_END_MOC_NAMESPACE
