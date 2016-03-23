#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <QMainWindow>

#include "../src/memory_network.hpp"
#include "../src-runner/experiment.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Dg_slider_sliderMoved(int position);

    void on_actionOpen_triggered();

    void on_runButton_clicked();

    void selectionChanged();

    void on_Lg_slider_sliderMoved(int position);

    void on_Eg_slider_sliderMoved(int position);

    void on_Ig_slider_sliderMoved(int position);

    void on_Amax_slider_sliderMoved(int position);

    void on_Amin_slider_sliderMoved(int position);

    void on_Arest_slider_sliderMoved(int position);

    void openRecentFile();

    void on_experiment_editor_textChanged();

    void on_actionSave_triggered();

    void on_action_Save_as_triggered();

    void on_actionQuit_triggered();

    void on_export_activation_plot_clicked();

    void on_export_weights_plot_clicked();

    void on_MaxFreq_spinBox_valueChanged();

private:

    void initializeWeightsPlot();
    void initializeActivationsPlot();

    /** Set up the plots size and captions.
     *
     * Typically called once an experiment is loaded,
     * but before the experiment ran.
     */
    void prepareActivationsPlot();
    void prepareWeightsPlot();

    void updateWeightsPlot();

    void loadExperiment(const QString& filename);
    void setupExperiment(const Experiment& expe);

    void update_expe_description_parameter(const QString& name, double value);

    void setCurrentFile(const QString &fileName);
    void updateRecentFileActions();
    QString strippedName(const QString& filename);

    enum { MaxRecentFiles = 5 };
    QAction *recentFileActs[MaxRecentFiles];

    Ui::MainWindow *ui;

    std::unique_ptr<MemoryNetwork> memory;

    Experiment expe;
    void saveFile(const QString &fileName);

    QString curFile;
};

#endif // MAINWINDOW_H
