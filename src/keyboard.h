class Keyboard {
    private:
        bool keys[16];

    public:
        Keyboard();
        bool isKeyPressed(unsigned char key);
        unsigned char waitForKeyPress();
        void keyDown(unsigned char key);
        void keyUp(unsigned char key);
};