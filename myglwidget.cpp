#include "myglwidget.h"
#include <iostream>

MyGLWidget::MyGLWidget(QWidget * parent) : QOpenGLWidget(parent){
    cpc.clear();
}
MyGLWidget::~MyGLWidget(){}

void MyGLWidget::initializeGL(){
    initializeOpenGLFunctions();
    glClearColor(28.0/255.0, 40.0/255.0, 79.0/255.0, 0.5f);
    glEnable(GL_DEPTH_TEST);
    m_program = new QOpenGLShaderProgram(this); 
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, "shaders/point_shader/vertex_shader.vs");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, "shaders/point_shader/fragment_shader.fs");
    m_program->link();
    m_model_loc = m_program->uniformLocation("model");
    m_view_loc = m_program->uniformLocation("view");
    m_projection_loc = m_program->uniformLocation("projection");
    m_color_loc = m_program->uniformLocation("input_color");

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    roll = 0.0f;
    pitch = 0.0f;
    yaw = 0.0f;

    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    
}
void MyGLWidget::resizeGL(int w, int h){
    width = w;
    height = h;
    glViewport(0, 0, w, h);
}
void MyGLWidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(28.0/255.0, 40.0/255.0, 79.0/255.0, 0.5f);


    QMatrix4x4 model;
    QMatrix4x4 view;
    QMatrix4x4 projection;
    projection.perspective(45.0f, width/height, 0.1f, 100.0f);

    view.lookAt(QVector3D(5.0, 0.0, 4.0), QVector3D(0.0, 0.0, 0.0), QVector3D(0.0, 0.0, 1.0));
    // QQuaternion quaternion = QQuaternion::fromEulerAngles(pitch, yaw, roll);
    QQuaternion quaternion = QQuaternion::fromEulerAngles(roll, pitch, yaw);

    std::cout<<"roll : "<<roll<<", pitch : "<<pitch<<", roll : "<<roll<<std::endl;
    model.translate(x, y, z);
    model.rotate(quaternion);


    m_program->bind();

    m_program->setUniformValue(m_model_loc, model);
    m_program->setUniformValue(m_view_loc, view);
    m_program->setUniformValue(m_projection_loc, projection);
    m_program->setUniformValue(m_color_bool, 1);

    int point_num = cpc.size();

    if(point_num == 0) {
        m_program->release();

    } else {

        float vertices[3*point_num];

        for(int i = 0; i < point_num; ++i) {
            vertices[3*i] = cpc[i][0];
            vertices[3*i+1] = cpc[i][1];
            vertices[3*i+2] = cpc[i][2];
        }


        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        QVector3D color = QVector3D(1.0, 0.0, 0.0);

        m_program->setUniformValue(m_color_loc, color);

        glDrawArrays(GL_POINTS, 0, point_num);

        // glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        m_program->release();
    }
}

void MyGLWidget::paint_pointcloud(std::vector<std::vector<float>> & ptcld){
    paintGL();
}


void MyGLWidget::paintstuff(){
    paintGL();
    std::cout<<"Pushed"<<std::endl;
    update();
}


void MyGLWidget::set_roll(float roll_){
    roll = roll_;
}
void MyGLWidget::set_pitch(float pitch_){
    pitch = pitch_;
}
void MyGLWidget::set_yaw(float yaw_){
    yaw = yaw_;
}
void MyGLWidget::set_x(float x_){
    x = x_;
}
void MyGLWidget::set_y(float y_){
    y = y_;
}
void MyGLWidget::set_z(float z_){
    z = z_;
}


void MyGLWidget::mousePressEvent(QMouseEvent *event){

    
    std::cout<<"FUCK"<<std::endl;
}

void MyGLWidget::mouseReleaseEvent(QMouseEvent *event){
    std::cout<<"UNFUCK"<<std::endl;
}


void MyGLWidget::mouseMoveEvent(QMouseEvent *event){
    std::cout<<"SHIT"<<std::endl;
}
