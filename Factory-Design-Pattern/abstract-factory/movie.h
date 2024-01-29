class Movie{
public:
    virtual void showName() = 0;
};

class HollywoodMovie :public Movie {
public:
    virtual void showName() = 0;
};

class BollywoodMovie : public Movie{
public:
    virtual void showName() = 0;
};


class HollywoodActionMovie : public HollywoodMovie {
public:
    void showName() override;
};

class HollywoodComedyMovie : public HollywoodMovie {
public:
    void showName() override;
};


class BollywoodActionMovie : public BollywoodMovie {
public:
    void showName() override;
};

class BollywoodComedyMovie : public BollywoodMovie {
public:
    void showName() override;
};

