#ifndef Place_h_included
#define Place_h_included
class Place {
 public:
  int row;
  int col;
  Place(int x = 0, int y = 0)
    {
      row = x;
      col = y;
    }
};
#endif

