#include "mypushbutton.h"
#include<QDebug>
#include<QPropertyAnimation>
//MyPushButton::MyPushButton(QWidget *parent)
//    : QPushButton{parent}
//{

//}

//构造函数 参数1 正常显示的图片路径  参数2 按下后显示的图片路径
MyPushButton::MyPushButton(QString normalImg, QString pressImg)
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool ret = pix.load(normalImg);
    //如果图片加载失败
    if(!ret)
    {
        qDebug()<<"图片加载失败";
        return;
    }

    //如果图片加载成功
    //设置图片固定大小
    this->setFixedSize(pix.width(),pix.height());

    //设置 不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");

    //设置图标
    this->setIcon(pix);

    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));
}

//弹跳特效
void MyPushButton::zoom1()//向下跳
{
    //创建动画对象
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    //设置动画时间间隔
    animation->setDuration(200);

    //起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve(QEasingCurve::OutBounce));

    //执行动画
    animation->start();
}

void MyPushButton::zoom2()//向上跳
{
    //创建动画对象
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    //设置动画时间间隔
    animation->setDuration(200);

    //起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve(QEasingCurve::OutBounce));

    //执行动画
    animation->start();
}

//重写按钮的 按下 和 释放 事件
void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(this->pressImgPath != "")//传入的按下图片不为空 说明需要有按下的状态，切换图片
    {
        QPixmap pix;
        bool ret = pix.load(this->pressImgPath);
        //如果图片加载失败
        if(!ret)
        {
            qDebug()<<"图片加载失败";
            return;
        }

        //如果图片加载成功
        //设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());

        //设置 不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");

        //设置图标
        this->setIcon(pix);

        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }

    //让父类执行其他内容
    return QPushButton::mousePressEvent(e);

}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->pressImgPath != "")//传入的按下图片不为空 说明需要有按下的状态，切换为初始图片
    {
        QPixmap pix;
        bool ret = pix.load(this->normalImgPath);
        //如果图片加载失败
        if(!ret)
        {
            qDebug()<<"图片加载失败";
            return;
        }

        //如果图片加载成功
        //设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());

        //设置 不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");

        //设置图标
        this->setIcon(pix);

        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }

    //让父类执行其他内容
    return QPushButton::mouseReleaseEvent(e);
}





