#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void showtime(void);
private slots:
    void on_blankUP_clicked();

    void on_blankDown_clicked();

    void on_lfUP_clicked();

    void on_lfDown_clicked();

    void on_pushButton_5_clicked();

    void on_biasUP_clicked();

    void on_biasDown_clicked();

    void on_pushButton_6_clicked();

    void on_blank_add_h_clicked();

    void on_blank_re_h_clicked();

    void on_lr_add_h_clicked();

    void on_lr_re_h_clicked();

    void on_bias_add_h_clicked();

    void on_bias_re_h_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
