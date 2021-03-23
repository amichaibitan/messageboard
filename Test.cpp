#include "Board.hpp"
#include "doctest.h"
#include <algorithm>
#include <string>


using namespace std;
using namespace ariel;


TEST_CASE("tests of dir: her -> post and read: ")
{
    Board bo;
    bo.post(15,15,Direction::Horizontal, "AmiBtn");
    CHECK(bo.read(15,15,Direction::Horizontal, 1) == (string)"A");
    CHECK(bo.read(15,15,Direction::Horizontal, 3) == (string)"Ami");
    CHECK(bo.read(15,15,Direction::Horizontal, 5) == (string)"AmiBt");
    CHECK(bo.read(15,15,Direction::Horizontal, 7) == (string)"AmiBtn_");
    CHECK(bo.read(15,13,Direction::Horizontal, 9) == (string)"__AmiBtn_");
    // another word that will replace
    bo.post(15,15,Direction::Horizontal, "abc");//"abcBtn"
    CHECK(bo.read(15,15,Direction::Horizontal, 3) == (string)"abc");
    CHECK(bo.read(15,14,Direction::Horizontal, 4) == (string)"_abc");
    CHECK(bo.read(15,15,Direction::Horizontal, 5) == (string)"abcBt");
    CHECK(bo.read(15,13,Direction::Horizontal, 9) == (string)"__abcBtn_");
  
};

TEST_CASE("tests of dir: ver -> post and read: ")
{
    Board bo;
     bo.post(15,15,Direction::Vertical, "AmiBtn");
     CHECK(bo.read(15,15,Direction::Vertical, 1) == (string)"A");
     CHECK(bo.read(15,14,Direction::Vertical, 3) == (string)"_Am");
     CHECK(bo.read(15,15,Direction::Vertical, 5) == (string)"AmiBt");
     CHECK(bo.read(15,13,Direction::Vertical, 7) == (string)"__AmiBt");
     CHECK(bo.read(15,18,Direction::Vertical, 5) == (string)"Btn__");
    // another word that will replace
     bo.post(15,17,Direction::Vertical, "abc");//"Amabcn"
     CHECK(bo.read(15,15,Direction::Vertical, 1) == (string)"A");
     CHECK(bo.read(15,14,Direction::Vertical, 3) == (string)"_Am");
     CHECK(bo.read(15,17,Direction::Vertical, 5) == (string)"abcn_");
     CHECK(bo.read(15,15,Direction::Vertical, 6) == (string)"Amabcn");
     CHECK(bo.read(15,14,Direction::Vertical, 7) == (string)"_Amabcn");
     CHECK(bo.read(15,14,Direction::Vertical, 8) == (string)"_Amabcn_");

    
};