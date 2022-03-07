/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 *
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using  namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}


TEST_CASE("Good input") {
    //1X1:
            CHECK(nospaces(mat(1, 1, '#', ')')) == nospaces("#\n"));
            CHECK(nospaces(mat(1, 1, '@', ')')) == nospaces("@\n"));
            CHECK(nospaces(mat(1, 1, '$', ')')) == nospaces("$\n"));
            CHECK(nospaces(mat(1, 1, '*', ')')) == nospaces("*\n"));
            CHECK(nospaces(mat(1, 1, '1', ')')) == nospaces("1\n"));
            CHECK(nospaces(mat(1, 1, '2', ')')) == nospaces("2\n"));
            CHECK(nospaces(mat(1, 1, '3', ')')) == nospaces("3\n"));
            CHECK(nospaces(mat(1, 1, '4', ')')) == nospaces("4\n"));



    //3X3:
            CHECK(nospaces(mat(3, 3, '@', '*')) == nospaces("@@@\n"
                                                            "@*@\n"
                                                            "@@@\n"));
            CHECK(nospaces(mat(3, 3, '@', '-')) == nospaces("@@@\n"
                                                            "@-@\n"
                                                            "@@@\n"));
            CHECK(nospaces(mat(3, 3, '#', '-')) == nospaces("###\n"
                                                            "#-#\n"
                                                            "###\n"));
            CHECK(nospaces(mat(3, 3, '@', '$')) == nospaces("@@@\n"
                                                            "@$@\n"
                                                            "@@@\n"));
            CHECK(nospaces(mat(3, 3, '@', '!')) == nospaces("@@@\n"
                                                            "@!@\n"
                                                            "@@@\n"));
            //3X5:


            CHECK(nospaces(mat(3, 5, '$', '+')) == nospaces("$$$\n"
                                                            "$+$\n"
                                                            "$+$\n"
                                                            "$+$\n"
                                                            "$$$\n"));
            //9X7:
             CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                            "@-------@\n"
                                                            "@-@@@@@-@\n"
                                                            "@-@---@-@\n"
                                                            "@-@@@@@-@\n"
                                                            "@-------@\n"
                                                            "@@@@@@@@@"));

            CHECK(nospaces(mat(9, 7, '1', '-')) == nospaces("111111111\n"
                                                            "1-------1\n"
                                                            "1-11111-1\n"
                                                            "1-1---1-1\n"
                                                            "1-11111-1\n"
                                                            "1-------1\n"
                                                            "111111111"));
            CHECK(nospaces(mat(9, 7, '1', '2')) == nospaces("111111111\n"
                                                            "122222221\n"
                                                            "121111121\n"
                                                            "121222121\n"
                                                            "121111121\n"
                                                            "122222221\n"
                                                            "111111111"));
            CHECK(nospaces(mat(9, 7, '1', '$')) == nospaces("111111111\n"
                                                            "1$$$$$$$1\n"
                                                            "1$11111$1\n"
                                                            "1$1$$$1$1\n"
                                                            "1$11111$1\n"
                                                            "1$$$$$$$1\n"
                                                            "111111111"));
            //13X5:
            CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
                                                             "@-----------@\n"
                                                             "@-@@@@@@@@@-@\n"
                                                             "@-----------@\n"
                                                             "@@@@@@@@@@@@@\n"));



}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));

    CHECK_THROWS(mat(2, 1, '$', '%'));
    CHECK_THROWS(mat(4, 1, '$', '%'));
    CHECK_THROWS(mat(6, 1, '$', '%'));
    CHECK_THROWS(mat(8, 1, '$', '%'));
    CHECK_THROWS(mat(10, 1, '$', '%'));
    CHECK_THROWS(mat(12, 1, '$', '%'));
    CHECK_THROWS(mat(14, 1, '$', '%'));

    CHECK_THROWS(mat(2, 1, '@', '%'));
    CHECK_THROWS(mat(4, 1, '@', '%'));
    CHECK_THROWS(mat(6, 1, '@', '%'));
    CHECK_THROWS(mat(8, 1, '@', '%'));
    CHECK_THROWS(mat(10, 1, '@', '%'));
    CHECK_THROWS(mat(12, 1, '@', '%'));
    CHECK_THROWS(mat(14, 1, '@', '%'));

    CHECK_THROWS(mat(2, 1, '@', '@'));
    CHECK_THROWS(mat(4, 1, '@', '@'));
    CHECK_THROWS(mat(6, 1, '@', '@'));
    CHECK_THROWS(mat(8, 1, '@', '@'));
    CHECK_THROWS(mat(10, 1, '@', '@'));
    CHECK_THROWS(mat(12, 1, '@', '@'));
    CHECK_THROWS(mat(14, 1, '@', '@'));

    CHECK_THROWS(mat(2, 3, '$', '%'));
    CHECK_THROWS(mat(4, 3, '$', '%'));
    CHECK_THROWS(mat(6, 3, '$', '%'));
    CHECK_THROWS(mat(8, 3, '$', '%'));
    CHECK_THROWS(mat(10, 3, '$', '%'));
    CHECK_THROWS(mat(12, 3, '$', '%'));
    CHECK_THROWS(mat(14, 3, '$', '%'));


    CHECK_THROWS(mat(2, 5, '$', '%'));
    CHECK_THROWS(mat(4, 5, '$', '%'));
    CHECK_THROWS(mat(6, 5, '$', '%'));
    CHECK_THROWS(mat(8, 5, '$', '%'));
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(12, 5, '$', '%'));
    CHECK_THROWS(mat(14, 5, '$', '%'));

    CHECK_THROWS(mat(22, 5, '$', '%'));
    CHECK_THROWS(mat(44, 5, '$', '%'));
    CHECK_THROWS(mat(66, 5, '$', '%'));
    CHECK_THROWS(mat(88, 5, '$', '%'));
    CHECK_THROWS(mat(100, 5, '$', '%'));
    CHECK_THROWS(mat(120, 5, '$', '%'));
    CHECK_THROWS(mat(140, 5, '$', '%'));


    CHECK_THROWS(mat(2, 7, '$', '%'));
    CHECK_THROWS(mat(4, 7, '$', '%'));
    CHECK_THROWS(mat(6, 7, '$', '%'));
    CHECK_THROWS(mat(8, 7, '$', '%'));
    CHECK_THROWS(mat(10, 7, '$', '%'));
    CHECK_THROWS(mat(12, 7, '$', '%'));
    CHECK_THROWS(mat(14, 7, '$', '%'));


    CHECK_THROWS(mat(2, 9, '$', '%'));
    CHECK_THROWS(mat(4, 9, '$', '%'));
    CHECK_THROWS(mat(6, 9, '$', '%'));
    CHECK_THROWS(mat(8, 9, '$', '%'));
    CHECK_THROWS(mat(10, 9, '$', '%'));
    CHECK_THROWS(mat(12, 9, '$', '%'));
    CHECK_THROWS(mat(14, 9, '$', '%'));

    CHECK_THROWS(mat(2, 9, '*', '%'));
    CHECK_THROWS(mat(4, 9, '*', '%'));
    CHECK_THROWS(mat(6, 9, '*', '%'));
    CHECK_THROWS(mat(8, 9, '*', '%'));
    CHECK_THROWS(mat(10, 9, '*', '%'));
    CHECK_THROWS(mat(12, 9, '*', '%'));
    CHECK_THROWS(mat(14, 9, '*', '%'));







}


/* Add more test cases here */