#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    /* Функция, которая вызвается во время нажатия кнопки 'To process' (Обработать).
     * 1. Считывается написанное пользователем сообщение.
     * 2. Если поле сообщения пустое, то считывается информация из входного файла.
     * 3. Если не указан ни входной файл ни пользовательское сообщение,
     *    то будет выведено соответствующее предупреждение об этом - вызывается
     *    функция printWarning().
     * 4. Проверяется, указан ли выходной файл, куда будет сохранен результат
     *    вычисления. Если не указан, то выводится предупреждение - вызывается
     *    функция printWarning().
     * 5. Выполняется вычисление результирующего колебания.
     * 6. Сохраняется результат вычисления в выходной файл.
     * */
    void toProcess();

    /* Функция, которая выводит окно с предупреждением.
     * 1. Открывается окно.
     * 2. В открывшемся окне отображается переданный в функцию текст 'warning' и
     *    кнопка 'OK'.
     * 3. При нажатии кнопки 'OK' закрывается окно с предупреждением - вызывается
     *    функция closeWarningWindow().
     * */
    void printWarning(QString warning);

    /* Функция, которая закрывает окно с предупреждением.
     * Функция вызывается при нажатии кнопки 'OK' в окно с предупреждением.
     * */
    void closeWarningWindow();

    /* Функция, которая очищает все текстовые поля (Message, Read from file, Save to file).
     * 1. Вызывается функция clearMessageEditLine().
     * 2. Вызывается функция clearReadEditLine().
     * 3. Вызывается функция clearSaveEditLine().
     * */
    void clearAllEditLines();

    /* Функция, которая очищает текстовое поле MessageEditLine.
     * */
    void clearMessageEditLine();

    /* Функция, которая очищает текстовое поле ReadEditLine.
     * */
    void clearReadEditLine();

    /* Функция, которая очищает текстовое поле SaveEditLine.
     * */
    void clearSaveEditLine();

    /* Функция, которая считывает пользовательское сообщение из текстового поля
     * или из текстового файла, указанного пользователем.
     * Если ничего не указано, вызывается функция printWarning().
     * */
    QString readMessage();

    /* Функция, которая считывает сообщение из текстового поля.
     * */
    QString readMessageFromEditLine();

    /* Функция, которая считывает сообщение из текстового файла.
     * */
    QString readMessageFromTextFile();

    /* Функция, которая сохраняет вычисленный сигнал в файл.
     * Функция должна знать что сохранить и куда сохранить.
     * */
    void saveOutputSignalToFile(QString result_signal, QString path);
};
#endif // WIDGET_H
