#ifndef REGISTERCOURSE_H
#define REGISTERCOURSE_H


class RegisterCourse{
    public:
        RegisterCourse(int input_class, int time);
        ~RegisterCourse();

        bool registerNotify();
    
        int class_number;
        int time;
};


#endif
