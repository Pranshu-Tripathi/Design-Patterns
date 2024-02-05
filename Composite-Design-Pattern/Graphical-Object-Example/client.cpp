#include "graphics.h"

int main(){
    // The client code can now create a tree of objects
    //        root
    //       /    \
    // lines_group circles_group
    //  /   \       /    \
    // l1   l2     c1    c2
    Group root("Root");
    Group lines_group("Lines");
    Group circles_group("Circles");
    Line l1, l2;
    Circle c1, c2;
    lines_group.add(&l1);
    lines_group.add(&l2);
    circles_group.add(&c1);
    circles_group.add(&c2);
    root.add(&lines_group);
    root.add(&circles_group);
    root.draw();
}