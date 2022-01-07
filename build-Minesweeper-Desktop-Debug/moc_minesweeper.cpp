/****************************************************************************
** Meta object code from reading C++ file 'minesweeper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Minesweeper/minesweeper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'minesweeper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Minesweeper_t {
    QByteArrayData data[13];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Minesweeper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Minesweeper_t qt_meta_stringdata_Minesweeper = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Minesweeper"
QT_MOC_LITERAL(1, 12, 12), // "starte_spiel"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 3), // "neu"
QT_MOC_LITERAL(4, 30, 13), // "hilfe_oeffnen"
QT_MOC_LITERAL(5, 44, 21), // "einstellungen_oeffnen"
QT_MOC_LITERAL(6, 66, 14), // "initialisieren"
QT_MOC_LITERAL(7, 81, 9), // "pausieren"
QT_MOC_LITERAL(8, 91, 7), // "beenden"
QT_MOC_LITERAL(9, 99, 17), // "statistik_oeffnen"
QT_MOC_LITERAL(10, 117, 13), // "timer_timeout"
QT_MOC_LITERAL(11, 131, 15), // "kachel_geklickt"
QT_MOC_LITERAL(12, 147, 15) // "flaggen_zaehler"

    },
    "Minesweeper\0starte_spiel\0\0neu\0"
    "hilfe_oeffnen\0einstellungen_oeffnen\0"
    "initialisieren\0pausieren\0beenden\0"
    "statistik_oeffnen\0timer_timeout\0"
    "kachel_geklickt\0flaggen_zaehler"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Minesweeper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   70,    2, 0x0a /* Public */,
       4,    0,   71,    2, 0x0a /* Public */,
       5,    0,   72,    2, 0x0a /* Public */,
       6,    0,   73,    2, 0x0a /* Public */,
       7,    0,   74,    2, 0x0a /* Public */,
       8,    0,   75,    2, 0x0a /* Public */,
       9,    0,   76,    2, 0x0a /* Public */,
      10,    0,   77,    2, 0x0a /* Public */,
      11,    0,   78,    2, 0x0a /* Public */,
      12,    1,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void Minesweeper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Minesweeper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->starte_spiel(); break;
        case 1: _t->neu(); break;
        case 2: _t->hilfe_oeffnen(); break;
        case 3: _t->einstellungen_oeffnen(); break;
        case 4: _t->initialisieren(); break;
        case 5: _t->pausieren(); break;
        case 6: _t->beenden(); break;
        case 7: _t->statistik_oeffnen(); break;
        case 8: _t->timer_timeout(); break;
        case 9: _t->kachel_geklickt(); break;
        case 10: _t->flaggen_zaehler((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Minesweeper::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Minesweeper::starte_spiel)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Minesweeper::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Minesweeper.data,
    qt_meta_data_Minesweeper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Minesweeper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Minesweeper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Minesweeper.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Minesweeper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Minesweeper::starte_spiel()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
