#include <iostream>
#include "lz77.h"

#include "testing.h"
#include "char_utils.h"
#include "file_utils.h"
#include "logger.h"

enum mode{COMPRESS, DECOMPRESS, UNDEFINED};

int main(int argc, char *argv[]) {

    //std::cout << lz77::compress("")

    //std::string testString = testing::generateRandomString(4000);
    //std::string testString = "Miałem robić mapę wczoraj, nie chciało mi się bo sił nie miałem karnąłem się na 193 i tyle, a dziś chciałem i znów plany się pokrzyżowały XD";

    //std::cout << testString << std::endl << std::endl;

    //std::string result = lz77::compress(testString, 256, 256);

    //testing::writeToFile(result, "compressed.txt");

    /*char *tab = {"cdabecdxyz"};

    lz77_word word{};
    for(int i = 9; i > 5; i--){
        if(char_utils::contain_word(tab, 5, 5, i, word)){
            std::cout << "(" << word.P + 1 << "," << word.C << "," << (int) word.S << ")" << std::endl;
        }

    }*/

    /*std::string test = "abcdefghijklnbhdoeps";
    char *tab;
    __int64 tab_size = testing::copyStringToTab(tab, test);
    __int64 lookahead_buf = tab_size/2;

    char_utils::copy_array(tab, tab_size, lookahead_buf, 4, 3);

    testing::printTab(tab, tab_size);*/

    /*lz77_word *tab;
    __int64 tab_size = testing::readWords(tab, "compressed.txt");

    std::string s;

    s = lz77::decompress(tab, tab_size, 256, 256);

    testing::writeToFile(s, "decompressed.txt");*/

    // For logging purpose.
    std::string info;

    // Parameters
    mode app_mode = mode::UNDEFINED;
    std::string input_filename, output_filename;
    __int64 lookahead_buffer_size, search_buffer_size;

    if(argc <= 1){
        std::cout << "Parameters for lz77compressor: " << std::endl;
        std::cout << "    -i  -  Input file name." << std::endl;
        std::cout << "    -o  -  Output file name." << std::endl;
        std::cout << "    -t  -  Choosing application mode (compress or 'c' / decompress or 'd')." << std::endl;
        std::cout << "    -n  -  Size of look ahead buffer (>0)." << std::endl;
        std::cout << "    -k  -  Size of search buffer (>0)." << std::endl;
        return 0;
    }

    for(int i = 1; i < argc; i++){
        if(argv[i] == (std::string) "-i"){
            i++;
            if(i >= argc){
                info = "Cannot read value for parameter \"";
                info += argv[i-1];
                info += "\". (Out of arguments)";
                logger::info(info);
                break;
            }
            input_filename = argv[i];
            continue;
        }
        if(argv[i] == (std::string) "-o"){
            i++;
            if(i >= argc){
                info = "Cannot read value for parameter \"";
                info += argv[i-1];
                info += "\". (Out of arguments)";
                logger::info(info);
                break;
            }
            output_filename = argv[i];
            continue;
        }
        if(argv[i] == (std::string) "-t"){
            i++;
            if(i >= argc){
                info = "Cannot read value for parameter \"";
                info += argv[i-1];
                info += "\". (Out of arguments)";
                logger::info(info);
                break;
            }
            if(argv[i] == (std::string) "c" || argv[i] == (std::string) "compress"){
                app_mode = mode::COMPRESS;
                continue;
            }
            if(argv[i] == (std::string) "d" || argv[i] == (std::string) "decompress"){
                app_mode = mode::DECOMPRESS;
                continue;
            }
            info = "Unknown value for parameter \"";
            info += argv[i-1];
            info += "\": \"";
            info += argv[i];
            info += "\".";
            logger::info(info);
            continue;
        }
        if(argv[i] == (std::string) "-n"){
            i++;
            if(i >= argc){
                info = "Cannot read value for parameter \"";
                info += argv[i-1];
                info += "\". (Out of arguments)";
                logger::info(info);
                break;
            }
            lookahead_buffer_size = (__int64) argv[i];
            continue;
        }
        if(argv[i] == (std::string) "-k"){
            i++;
            if(i >= argc){
                info = "Cannot read value for parameter \"";
                info += argv[i-1];
                info += "\". (Out of arguments)";
                logger::info(info);
                break;
            }
            search_buffer_size = (__int64) argv[i];
            continue;
        }
        info = "Unknown parameter \"";
        info += argv[i];
        info += "\".";
        logger::info(info);
    }

    if(app_mode == mode::UNDEFINED){
        logger::info("Undefined mode (compress/decompress).");
        return 0;
    }

    if(input_filename.empty()){
        logger::info("Undefined input file name.");
        return 0;
    }

    if(output_filename.empty()){
        logger::info("Undefined output file name.");
        return 0;
    }

    if(lookahead_buffer_size <= 0){
        logger::info("Size of look ahead buffer is too small. (should be > 0)");
        return 0;
    }

    if(search_buffer_size <= 0){
        logger::info("Size of search buffer is too small. (should be > 0)");
        return 0;
    }

    return 0;
}
