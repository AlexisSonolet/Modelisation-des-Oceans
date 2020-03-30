#pragma once

class Height
{
    public:
        // Basic methods
        Height();
        ~Height();
        Height(int n_x, int n_y, double L_x, double L_y);
        Height(Height &&hauteurs);
        Height(Height const &hauteurs);
        Height operator=(Height &&hauteurs);
        Height operator=(Height const &hauteurs);
        double operator()(int x, int y);
        // Setters and getters
        void setLx(double value);
        double getLx();
        void setLy(double value);
        double getLy();
        void setNx(int value);
        double getNx();
        void setNy(int value);
        double getNy();
        void setValue(int x, int y, double value);
        // Other methods
        void plot(std::string path);
    private:
        double Lx, Ly;
        int nx, ny;
        double** heights;
};
