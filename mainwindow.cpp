#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent, QRect Screen)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFocus(Qt::NoFocusReason);
    this->resize(Screen.width()*3/5, height());
    this->setFixedSize(this->width(), this->width()*0.275);
    //setWindowFlags( (windowFlags() | Qt::CustomizeWindowHint) & ~Qt::WindowMaximizeButtonHint);
    T=new QTimer(this);
    connect(T, SIGNAL(timeout()), this, SLOT(Tick()));
    int BSize=std::min((int)(0.05*this->width()), (int)(0.166*this->height()));
    for (int i=0; i<81; i++){
        Btns[i]=new QPushButton(this);
        Btns[i]->setFocusPolicy(Qt::NoFocus);
        Btns[i]->resize(BSize, BSize);

    }
    for (int i=0; i<32; i++){
        R_KEYS[i]=wchar_t(i+L'а');
    }
    R_KEYS[32]=L'ё';
    for (int i=0; i<26; i++){
        E_KEYS[i]=wchar_t(i+'a');
    }
    E_KEYS[26]='`';
    E_KEYS[27]='[';
    E_KEYS[28]=']';
    E_KEYS[29]=';';
    E_KEYS[30]='\'';
    E_KEYS[31]=',';
    E_KEYS[32]='.';
    for (int i=0; i<33; i++){
        UP_CASE[R_KEYS[i]]=R_KEYS[i];
    }
    for (int i=0; i<33; i++){
        UP_CASE[E_KEYS[i]]=E_KEYS[i];
    }
    for (int i=0; i<32; i++){
        UP_CASE[R_KEYS[i]]=wchar_t(R_KEYS[i]-32);
    }
    UP_CASE[L'ё']=L'Ё';
    UP_CASE[L'Ё']=L'ё';
    for (int i=0; i<32; i++){
        UP_CASE[UP_CASE[R_KEYS[i]]]=R_KEYS[i];
    }

    for (int i=0; i<26; i++){
        UP_CASE[E_KEYS[i]]=wchar_t(E_KEYS[i]-32);
    }
    for (int i=0; i<26; i++){
        UP_CASE[UP_CASE[E_KEYS[i]]]=E_KEYS[i];
    }
    LIBA[L'ё']='`';
    LIBA[L'й']='q';
    LIBA[L'ц']='w';
    LIBA[L'у']='e';
    LIBA[L'к']='r';
    LIBA[L'е']='t';
    LIBA[L'н']='y';
    LIBA[L'г']='u';
    LIBA[L'ш']='i';
    LIBA[L'щ']='o';
    LIBA[L'з']='p';
    LIBA[L'х']='[';
    LIBA[L'ъ']=']';
    LIBA[L'ф']='a';
    LIBA[L'ы']='s';
    LIBA[L'в']='d';
    LIBA[L'а']='f';
    LIBA[L'п']='g';
    LIBA[L'р']='h';
    LIBA[L'о']='j';
    LIBA[L'л']='k';
    LIBA[L'д']='l';
    LIBA[L'ж']=';';
    LIBA[L'э']='\'';
    LIBA[L'я']='z';
    LIBA[L'ч']='x';
    LIBA[L'с']='c';
    LIBA[L'м']='v';
    LIBA[L'и']='b';
    LIBA[L'т']='n';
    LIBA[L'ь']='m';
    LIBA[L'б']=',';
    LIBA[L'ю']='.';
    for (int i=0; i<33; i++){
        LIBA[LIBA[R_KEYS[i]]]=R_KEYS[i];
    }
    for (int i=0; i<33; i++){
        LIBA[UP_CASE[R_KEYS[i]]]=UP_CASE[LIBA[R_KEYS[i]]];
    }
    for (int i=0; i<33; i++){
        LIBA[LIBA[UP_CASE[R_KEYS[i]]]]=UP_CASE[R_KEYS[i]];
    }
    //LIBA
    for (int i=1; i<14; i++){
        Btns[i]->move(Btns[i-1]->x()+Btns[i-1]->width(), 0);
    }
    Btns[13]->resize((int)(BSize*1.27), BSize);
    Btns[14]->setGeometry(0, Btns[14]->height(), (int)(BSize*1.266), BSize);
    for (int i=15; i<28; i++){
        Btns[i]->move(Btns[i-1]->x()+Btns[i-1]->width(), Btns[i]->height());
    }
    Btns[28]->setGeometry(0, Btns[28]->height()*2, (int)(BSize*1.644), BSize);
    for (int i=29; i<41; i++){
        Btns[i]->move(Btns[i-1]->x()+Btns[i-1]->width(), Btns[i]->height()*2);
    }
    Btns[40]->resize((int)(BSize*1.635), BSize);
    Btns[41]->move((int)(BSize*2.117), Btns[41]->height()*3);
    for (int i=42; i<51; i++){
        Btns[i]->move(Btns[i-1]->x()+Btns[i-1]->width(), Btns[i]->height()*3);
    }
    Btns[52]->setGeometry(0, BSize*5, this->width()-2, this->height()-BSize*5);
    Btns[51]->setGeometry(4*BSize, BSize*4, (int)(5.266*BSize), BSize);

    Btns[53]->move(Btns[13]->x()+Btns[13]->width()+BSize, 0);
    for (int i=54; i<=59; i++){
        Btns[i]->move(Btns[i-1]->x()+Btns[i-1]->width(), 0);
    }

    Btns[60]->move(Btns[13]->x()+Btns[13]->width()+BSize, Btns[60]->height());
    for (int i=61; i<=66; i++){
        Btns[i]->move(Btns[i-1]->x()+Btns[i-1]->width(), Btns[i]->height());
    }


    Btns[67]->move(Btns[13]->x()+Btns[13]->width()+BSize, Btns[67]->height()*2);
    for (int i=68; i<=73; i++){
        Btns[i]->move(Btns[i-1]->x()+Btns[i-1]->width(), Btns[i]->height()*2);
    }

    Btns[74]->move(Btns[13]->x()+Btns[13]->width()+BSize, Btns[74]->height()*3);
    for (int i=75; i<=80; i++){
        Btns[i]->move(Btns[i-1]->x()+Btns[i-1]->width(), Btns[i]->height()*3);
    }

    connect(Btns[0], SIGNAL(pressed()), this, SLOT(PBio_click()));  /*БУКВА Ё*/
    connect(Btns[1], SIGNAL(pressed()), this, SLOT(PB1_click()));
    connect(Btns[2], SIGNAL(pressed()), this, SLOT(PB2_click()));
    connect(Btns[3], SIGNAL(pressed()), this, SLOT(PB3_click()));
    connect(Btns[4], SIGNAL(pressed()), this, SLOT(PB4_click()));
    connect(Btns[5], SIGNAL(pressed()), this, SLOT(PB5_click()));
    connect(Btns[6], SIGNAL(pressed()), this, SLOT(PB6_click()));
    connect(Btns[7], SIGNAL(pressed()), this, SLOT(PB7_click()));
    connect(Btns[8], SIGNAL(pressed()), this, SLOT(PB8_click()));
    connect(Btns[9], SIGNAL(pressed()), this, SLOT(PB9_click()));
    connect(Btns[10], SIGNAL(pressed()), this, SLOT(PB0_click()));
    connect(Btns[11], SIGNAL(pressed()), this, SLOT(PBminus_click()));
    connect(Btns[12], SIGNAL(pressed()), this, SLOT(PBequal_click()));
    connect(Btns[13], SIGNAL(pressed()), this, SLOT(PBbackspace_click()));
    Btns[0]->setText("`");
    Btns[1]->setText("1");
    Btns[2]->setText("2");
    Btns[3]->setText("3");
    Btns[4]->setText("4");
    Btns[5]->setText("5");
    Btns[6]->setText("6");
    Btns[7]->setText("7");
    Btns[8]->setText("8");
    Btns[9]->setText("9");
    Btns[10]->setText("0");
    Btns[11]->setText("-");
    Btns[12]->setText("=");
    Btns[13]->setText("<--");

    connect(Btns[14], SIGNAL(pressed()), this, SLOT(PBtab_click()));
    connect(Btns[15], SIGNAL(pressed()), this, SLOT(PBQ_click()));
    connect(Btns[16], SIGNAL(pressed()), this, SLOT(PBW_click()));
    connect(Btns[17], SIGNAL(pressed()), this, SLOT(PBE_click()));
    connect(Btns[18], SIGNAL(pressed()), this, SLOT(PBR_click()));
    connect(Btns[19], SIGNAL(pressed()), this, SLOT(PBT_click()));
    connect(Btns[20], SIGNAL(pressed()), this, SLOT(PBY_click()));
    connect(Btns[21], SIGNAL(pressed()), this, SLOT(PBU_click()));
    connect(Btns[22], SIGNAL(pressed()), this, SLOT(PBI_click()));
    connect(Btns[23], SIGNAL(pressed()), this, SLOT(PBO_click()));
    connect(Btns[24], SIGNAL(pressed()), this, SLOT(PBP_click()));
    connect(Btns[25], SIGNAL(pressed()), this, SLOT(PBlsb_click()));  //LEFT SQUARE BOARD
    connect(Btns[26], SIGNAL(pressed()), this, SLOT(PBrsb_click()));  //RIGHT SQUARE BOARD
    connect(Btns[27], SIGNAL(pressed()), this, SLOT(PBfsl_click()));  //FALLING STICK LEFT
    Btns[14]->setText("Tab");
    Btns[15]->setText("Q");
    Btns[16]->setText("W");
    Btns[17]->setText("E");
    Btns[18]->setText("R");
    Btns[19]->setText("T");
    Btns[20]->setText("Y");
    Btns[21]->setText("U");
    Btns[22]->setText("I");
    Btns[23]->setText("O");
    Btns[24]->setText("P");
    Btns[25]->setText("[");
    Btns[26]->setText("]");
    Btns[27]->setText("\\");

    connect(Btns[28], SIGNAL(pressed()), this, SLOT(PBcaps_click()));
    connect(Btns[29], SIGNAL(pressed()), this, SLOT(PBA_click()));
    connect(Btns[30], SIGNAL(pressed()), this, SLOT(PBS_click()));
    connect(Btns[31], SIGNAL(pressed()), this, SLOT(PBD_click()));
    connect(Btns[32], SIGNAL(pressed()), this, SLOT(PBF_click()));
    connect(Btns[33], SIGNAL(pressed()), this, SLOT(PBG_click()));
    connect(Btns[34], SIGNAL(pressed()), this, SLOT(PBH_click()));
    connect(Btns[35], SIGNAL(pressed()), this, SLOT(PBJ_click()));
    connect(Btns[36], SIGNAL(pressed()), this, SLOT(PBK_click()));
    connect(Btns[37], SIGNAL(pressed()), this, SLOT(PBL_click()));
    connect(Btns[38], SIGNAL(pressed()), this, SLOT(PBzh_click()));   //ТОЧКА С ЗАПЯТОЙ
    connect(Btns[39], SIGNAL(pressed()), this, SLOT(PBlit_click()));  //ОДИНОЧНЫЕ КАВЫЧКИ
    connect(Btns[40], SIGNAL(pressed()), this, SLOT(PBenter_click()));
    Btns[28]->setText("caps lock");
    Btns[29]->setText("A");
    Btns[30]->setText("S");
    Btns[31]->setText("D");
    Btns[32]->setText("F");
    Btns[33]->setText("G");
    Btns[34]->setText("H");
    Btns[35]->setText("J");
    Btns[36]->setText("K");
    Btns[37]->setText("L");
    Btns[38]->setText(";");
    Btns[39]->setText("'");
    Btns[40]->setText("Enter");

    connect(Btns[41], SIGNAL(pressed()), this, SLOT(PBZ_click()));
    connect(Btns[42], SIGNAL(pressed()), this, SLOT(PBX_click()));
    connect(Btns[43], SIGNAL(pressed()), this, SLOT(PBC_click()));
    connect(Btns[44], SIGNAL(pressed()), this, SLOT(PBV_click()));
    connect(Btns[45], SIGNAL(pressed()), this, SLOT(PBB_click()));
    connect(Btns[46], SIGNAL(pressed()), this, SLOT(PBN_click()));
    connect(Btns[47], SIGNAL(pressed()), this, SLOT(PBM_click()));
    connect(Btns[48], SIGNAL(pressed()), this, SLOT(PBltb_click()));  //LEFT TRIANGLE BOARD
    connect(Btns[49], SIGNAL(pressed()), this, SLOT(PBrtb_click()));  //RIGHT TRIANGLE BOARD
    Btns[50]->hide();
    connect(Btns[51], SIGNAL(pressed()), this, SLOT(PBSpace_click()));
    connect(Btns[52], SIGNAL(pressed()), this, SLOT(PBchgLng_click()));
    Btns[41]->setText("Z");
    Btns[42]->setText("X");
    Btns[43]->setText("C");
    Btns[44]->setText("V");
    Btns[45]->setText("B");
    Btns[46]->setText("N");
    Btns[47]->setText("M");
    Btns[48]->setText(",");
    Btns[49]->setText(".");
    Btns[50]->setText("/");

    Btns[52]->setText("Change Layout");

    connect(Btns[53], SIGNAL(pressed()), this, SLOT(PBS1_click()));
    connect(Btns[54], SIGNAL(pressed()), this, SLOT(PBS2_click()));
    connect(Btns[55], SIGNAL(pressed()), this, SLOT(PBS3_click()));
    connect(Btns[56], SIGNAL(pressed()), this, SLOT(PBS4_click()));
    connect(Btns[57], SIGNAL(pressed()), this, SLOT(PBS5_click()));
    connect(Btns[58], SIGNAL(pressed()), this, SLOT(PBS6_click()));
    connect(Btns[59], SIGNAL(pressed()), this, SLOT(PBS7_click()));
    connect(Btns[60], SIGNAL(pressed()), this, SLOT(PBS8_click()));
    connect(Btns[61], SIGNAL(pressed()), this, SLOT(PBS9_click()));
    connect(Btns[62], SIGNAL(pressed()), this, SLOT(PBS10_click()));
    connect(Btns[63], SIGNAL(pressed()), this, SLOT(PBS11_click()));
    connect(Btns[64], SIGNAL(pressed()), this, SLOT(PBS12_click()));
    connect(Btns[65], SIGNAL(pressed()), this, SLOT(PBS13_click()));
    connect(Btns[66], SIGNAL(pressed()), this, SLOT(PBS14_click()));
    connect(Btns[67], SIGNAL(pressed()), this, SLOT(PBS15_click()));
    connect(Btns[68], SIGNAL(pressed()), this, SLOT(PBS16_click()));
    connect(Btns[69], SIGNAL(pressed()), this, SLOT(PBS17_click()));
    connect(Btns[70], SIGNAL(pressed()), this, SLOT(PBS18_click()));
    connect(Btns[71], SIGNAL(pressed()), this, SLOT(PBS19_click()));
    connect(Btns[72], SIGNAL(pressed()), this, SLOT(PBS20_click()));
    connect(Btns[73], SIGNAL(pressed()), this, SLOT(PBS21_click()));
    connect(Btns[74], SIGNAL(pressed()), this, SLOT(PBS22_click()));
    connect(Btns[75], SIGNAL(pressed()), this, SLOT(PBS23_click()));
    connect(Btns[76], SIGNAL(pressed()), this, SLOT(PBS24_click()));
    connect(Btns[77], SIGNAL(pressed()), this, SLOT(PBS25_click()));
    connect(Btns[78], SIGNAL(pressed()), this, SLOT(PBS26_click()));
    connect(Btns[79], SIGNAL(pressed()), this, SLOT(PBS27_click()));
    connect(Btns[80], SIGNAL(pressed()), this, SLOT(PBS28_click()));
    Btns[53]->setText("!");
    Btns[54]->setText("\"");
    Btns[55]->setText("№");
    Btns[56]->setText(";");
    Btns[57]->setText("%");
    Btns[58]->setText(":");
    Btns[59]->setText("?");
    Btns[60]->setText("*");
    Btns[61]->setText("(");
    Btns[62]->setText(")");
    Btns[63]->setText("_");
    Btns[64]->setText("+");
    Btns[65]->setText("~");
    Btns[66]->setText("@");
    Btns[67]->setText("#");
    Btns[68]->setText("$");
    Btns[69]->setText("^");
    Btns[70]->setText("&&");
    Btns[71]->setText("{");
    Btns[72]->setText("}");
    Btns[73]->setText("|");
    Btns[74]->setText("\\");
    Btns[75]->setText("/");
    Btns[76]->setText(":");
    Btns[77]->setText("\"");
    Btns[78]->setText("<");
    Btns[79]->setText(">");
    Btns[80]->setText(".");
}

MainWindow::~MainWindow()
{
    T->stop();
    for (unsigned int i=0; i<sizeof(Btns)/sizeof(QPushButton*); i++){
        delete Btns[i];
    }
    delete T;
    delete ui;
}

void MainWindow::EmulateDown(int x){
    SetFocus(lwind);
    PostMessage(lwind, WM_INPUTLANGCHANGEREQUEST, 1, this->lang);
    bool ba=PostMessage(lwind, WM_KEYDOWN, x, 0);
    if (!(ba)) QMessageBox::critical(this, "Error", "Fail command");
    SetFocus(twind);
}

void MainWindow::EmulateUp(int x){
    SetFocus(lwind);
    PostMessage(lwind, WM_INPUTLANGCHANGEREQUEST, 1, this->lang);
    bool ba=PostMessage(lwind, WM_KEYUP, x, 0);
    if (!(ba)) QMessageBox::critical(this, "Error", "Fail command");
    SetFocus(twind);
}

void MainWindow::EmulateChar(wchar_t x, bool flag_simb=false){
    SetFocus(lwind);

    PostMessage(lwind, WM_INPUTLANGCHANGEREQUEST, 1, this->lang);
    if (!flag_simb){
        if (this->lang==this->Eng){
            for (int i=0; i<34; i++){
                if (this->R_KEYS[i]==x){
                    x=LIBA[x];
                    break;
                }
            }
        }else{
            for (int i=0; i<34; i++){
                if (this->E_KEYS[i]==x){
                    x=LIBA[x];
                    break;
                }
            }
        }
        if (CAPS){
            x=UP_CASE[x];
        }
    }
    bool ba=PostMessage(lwind, WM_CHAR, x, 0);
    if (!(ba)) QMessageBox::critical(this, "Error", "Fail command");
    SetFocus(twind);
}


int temp=1;
char* ab=new char[100];

void MainWindow::Tick(){
    wind=GetForegroundWindow();
    GetWindowTextA(wind, ab, 100);
    QString a=QString::fromUtf8(ab);
    if(a.length()!=0){
        if (twind!=wind){

            if(GetAsyncKeyState(VK_LBUTTON)){
                POINT P;
                GetCursorPos(&P);
                tt=WindowFromPoint(P);
                lwind=tt;
            }
        }
    }
}

void MainWindow::PBio_click(){EmulateChar('`');}  //БУКВА Ё
void MainWindow::PBtab_click(){EmulateUp(9);}
void MainWindow::PBcaps_click(){
    this->CAPS=!CAPS;
    QString tempTXT=Btns[0]->text();
    wchar_t ttt [20];
    tempTXT.toWCharArray(ttt);
    Btns[0]->setText(QString(UP_CASE[ttt[0]]));
    for (int i=15; i<=26; i++){
        tempTXT=Btns[i]->text();
        tempTXT.toWCharArray(ttt);
        Btns[i]->setText(QString(UP_CASE[ttt[0]]));
    }
    for (int i=29; i<=39; i++){
        tempTXT=Btns[i]->text();
        tempTXT.toWCharArray(ttt);
        Btns[i]->setText(QString(UP_CASE[ttt[0]]));
    }
    for (int i=41; i<=50; i++){
        tempTXT=Btns[i]->text();
        tempTXT.toWCharArray(ttt);
        Btns[i]->setText(QString(UP_CASE[ttt[0]]));
    }
}
void MainWindow::PB1_click(){EmulateUp(49);}
void MainWindow::PB2_click(){EmulateUp(50);}
void MainWindow::PB3_click(){EmulateUp(51);}
void MainWindow::PB4_click(){EmulateUp(52);}
void MainWindow::PB5_click(){EmulateUp(53);}
void MainWindow::PB6_click(){EmulateUp(54);}
void MainWindow::PB7_click(){EmulateUp(55);}
void MainWindow::PB8_click(){EmulateUp(56);}
void MainWindow::PB9_click(){EmulateUp(57);}
void MainWindow::PB0_click(){EmulateUp(48);}
void MainWindow::PBminus_click(){EmulateUp(109);}
void MainWindow::PBequal_click(){EmulateUp(107);}
void MainWindow::PBbackspace_click(){EmulateDown(8);}
void MainWindow::PBQ_click(){EmulateChar('q');}
void MainWindow::PBW_click(){EmulateChar('w');}
void MainWindow::PBE_click(){EmulateChar('e');}
void MainWindow::PBR_click(){EmulateChar('r');}
void MainWindow::PBT_click(){EmulateChar('t');}
void MainWindow::PBY_click(){EmulateChar('y');}
void MainWindow::PBU_click(){EmulateChar('u');}
void MainWindow::PBI_click(){EmulateChar('i');}
void MainWindow::PBO_click(){EmulateChar('o');}
void MainWindow::PBP_click(){EmulateChar('p');}
void MainWindow::PBlsb_click(){EmulateChar('[');}  //LEFT SQUARE BOARD
void MainWindow::PBrsb_click(){EmulateChar(']');}  //RIGHT SQUARE BOARD
void MainWindow::PBfsl_click(){EmulateChar('\\');}  //FALLING STICK LEFT
void MainWindow::PBA_click(){EmulateChar('a');}
void MainWindow::PBS_click(){EmulateChar('s');}
void MainWindow::PBD_click(){EmulateChar('d');}
void MainWindow::PBF_click(){EmulateChar('f');}
void MainWindow::PBG_click(){EmulateChar('g');}
void MainWindow::PBH_click(){EmulateChar('h');}
void MainWindow::PBJ_click(){EmulateChar('j');}
void MainWindow::PBK_click(){EmulateChar('k');}
void MainWindow::PBL_click(){EmulateChar('l');}
void MainWindow::PBzh_click(){EmulateChar(';');}   //ТОЧКА С ЗАПЯТОЙ
void MainWindow::PBlit_click(){EmulateChar('\'');}  //ОДИНОЧНЫЕ КАВЫЧКИ
void MainWindow::PBenter_click(){EmulateDown(13);}
void MainWindow::PBZ_click(){EmulateChar('z');}
void MainWindow::PBX_click(){EmulateChar('x');}
void MainWindow::PBC_click(){EmulateChar('c');}
void MainWindow::PBV_click(){EmulateChar('v');}
void MainWindow::PBB_click(){EmulateChar('b');}
void MainWindow::PBN_click(){EmulateChar('n');}
void MainWindow::PBM_click(){EmulateChar('m');}
void MainWindow::PBltb_click(){EmulateChar(',');}  //LEFT TRIANGLE BOARD
void MainWindow::PBrtb_click(){EmulateChar('.');}  //RIGHT TRIANGLE BOARD
void MainWindow::PBfsr_click(){EmulateChar('/');}  //FALLING STICK RIGHT
void MainWindow::PBSpace_click(){EmulateDown(32);}
void MainWindow::PBchgLng_click(){
    if (this->lang==this->Eng){
        this->lang=this->Rus;
    }else
        this->lang=this->Eng;
    QString tempTXT=Btns[0]->text();
    wchar_t ttt [20];
    tempTXT.toWCharArray(ttt);
    Btns[0]->setText(QString(LIBA[ttt[0]]));
    for (int i=15; i<=26; i++){
        tempTXT=Btns[i]->text();
        tempTXT.toWCharArray(ttt);
        Btns[i]->setText(QString(LIBA[ttt[0]]));
    }
    for (int i=29; i<=39; i++){
        tempTXT=Btns[i]->text();
        tempTXT.toWCharArray(ttt);
        Btns[i]->setText(QString(LIBA[ttt[0]]));
    }
    for (int i=41; i<=50; i++){
        tempTXT=Btns[i]->text();
        tempTXT.toWCharArray(ttt);
        Btns[i]->setText(QString(LIBA[ttt[0]]));
    }
}
void MainWindow::PBS1_click(){EmulateChar('!', true);}
void MainWindow::PBS2_click(){EmulateChar('"', true);}
void MainWindow::PBS3_click(){EmulateChar(L'№', true);}
void MainWindow::PBS4_click(){EmulateChar(';', true);}
void MainWindow::PBS5_click(){EmulateChar('%', true);}
void MainWindow::PBS6_click(){EmulateChar(':', true);}
void MainWindow::PBS7_click(){EmulateChar('?', true);}
void MainWindow::PBS8_click(){EmulateChar('*', true);}
void MainWindow::PBS9_click(){EmulateChar('(', true);}
void MainWindow::PBS10_click(){EmulateChar(')', true);}
void MainWindow::PBS11_click(){EmulateChar('_', true);}
void MainWindow::PBS12_click(){EmulateChar('+', true);}
void MainWindow::PBS13_click(){EmulateChar('~', true);}
void MainWindow::PBS14_click(){EmulateChar('@', true);}
void MainWindow::PBS15_click(){EmulateChar('#', true);}
void MainWindow::PBS16_click(){EmulateChar('$', true);}
void MainWindow::PBS17_click(){EmulateChar('^', true);}
void MainWindow::PBS18_click(){EmulateChar('&', true);}
void MainWindow::PBS19_click(){EmulateChar('{', true);}
void MainWindow::PBS20_click(){EmulateChar('}', true);}
void MainWindow::PBS21_click(){EmulateChar('|', true);}
void MainWindow::PBS22_click(){EmulateChar('\\', true);}
void MainWindow::PBS23_click(){EmulateChar('/', true);}
void MainWindow::PBS24_click(){EmulateChar(':', true);}
void MainWindow::PBS25_click(){EmulateChar('"', true);}
void MainWindow::PBS26_click(){EmulateChar('<', true);}
void MainWindow::PBS27_click(){EmulateChar('>', true);}
void MainWindow::PBS28_click(){EmulateChar('.', true);}
