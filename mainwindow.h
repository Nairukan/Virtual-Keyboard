#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QCoreApplication>
#include <QFocusEvent>
#include <windows.h>
#include <QTimer>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPushButton>
#include <algorithm>
#include <map>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent, QRect Screen);
    ~MainWindow();
    HWND twind, wind, lwind, tt;
    bool CAPS=true;
    QPushButton* Btns[81];     //0x00000409 0x04090409
    LPARAM Eng=0x04090409, Rus=0x04190419, lang=Eng;
    wchar_t R_KEYS[34], E_KEYS[34];
    std::map<wchar_t, wchar_t> LIBA, UP_CASE;
    void EmulateChar(wchar_t x, bool flag_simb);
    void EmulateDown(int x);
    void EmulateUp(int x);
    QTimer* T=nullptr;
    Ui::MainWindow *ui;
private slots:
    void Tick();
    void PBio_click();  //БУКВА Ё
    void PBtab_click();
    void PBcaps_click();
    void PB1_click();
    void PB2_click();
    void PB3_click();
    void PB4_click();
    void PB5_click();
    void PB6_click();
    void PB7_click();
    void PB8_click();
    void PB9_click();
    void PB0_click();
    void PBminus_click();
    void PBequal_click();
    void PBbackspace_click();
    void PBQ_click();
    void PBW_click();
    void PBE_click();
    void PBR_click();
    void PBT_click();
    void PBY_click();
    void PBU_click();
    void PBI_click();
    void PBO_click();
    void PBP_click();
    void PBlsb_click();  //LEFT SQUARE BOARD
    void PBrsb_click();  //RIGHT SQUARE BOARD
    void PBfsl_click();  //FALLING STICK LEFT
    void PBA_click();
    void PBS_click();
    void PBD_click();
    void PBF_click();
    void PBG_click();
    void PBH_click();
    void PBJ_click();
    void PBK_click();
    void PBL_click();
    void PBzh_click();   //ТОЧКА С ЗАПЯТОЙ
    void PBlit_click();  //ОДИНОЧНЫЕ КАВЫЧКИ
    void PBenter_click();
    void PBZ_click();
    void PBX_click();
    void PBC_click();
    void PBV_click();
    void PBB_click();
    void PBN_click();
    void PBM_click();
    void PBltb_click();  //LEFT TRIANGLE BOARD
    void PBrtb_click();  //RIGHT TRIANGLE BOARD
    void PBfsr_click();  //FALLING STICK RIGHT
    void PBSpace_click();
    void PBchgLng_click();
    void PBS1_click();
    void PBS2_click();
    void PBS3_click();
    void PBS4_click();
    void PBS5_click();
    void PBS6_click();
    void PBS7_click();
    void PBS8_click();
    void PBS9_click();
    void PBS10_click();
    void PBS11_click();
    void PBS12_click();
    void PBS13_click();
    void PBS14_click();
    void PBS15_click();
    void PBS16_click();
    void PBS17_click();
    void PBS18_click();
    void PBS19_click();
    void PBS20_click();
    void PBS21_click();
    void PBS22_click();
    void PBS23_click();
    void PBS24_click();
    void PBS25_click();
    void PBS26_click();
    void PBS27_click();
    void PBS28_click();
private:
};
#endif // MAINWINDOW_H
