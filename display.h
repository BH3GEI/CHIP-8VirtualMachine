class Display {
    private:
        bool screen[64 * 32];

    public:
        void clear();
        void drawPixel(int x, int y);
};