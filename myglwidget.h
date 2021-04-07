#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H
#include <QOpenGLWidget>
// #include <QOpenGLFunctions>
#include <QOpenGLExtraFunctions>
#include <QMatrix4x4>
#include <QOpenGLShaderProgram>
#include <QQuaternion>

class MyGLWidget : public QOpenGLWidget, public QOpenGLExtraFunctions
{
    Q_OBJECT
public:
    MyGLWidget(QWidget * parent = nullptr);
    ~MyGLWidget();

    void paintstuff();

signals:

public slots:
    void set_roll(float roll_);
    void set_pitch(float pitch_);
    void set_yaw(float yaw_);
    void set_x(float x_);
    void set_y(float y_);
    void set_z(float z_);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    QOpenGLShaderProgram * m_program;

    GLuint m_model_loc;
    GLuint m_view_loc;
    GLuint m_projection_loc;
    GLuint m_color_loc;

    unsigned int VBO, VAO, EBO, FBO;

    int width;
    int height;
    
    float roll;
    float pitch;
    float yaw;
    float x;
    float y;
    float z;
};

#endif // MYGLWIDGET_H