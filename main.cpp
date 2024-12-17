#include <iostream>
#include "lz77.h"

#include "char_utils.h"
#include "file_utils.h"
#include "logger.h"
#include "testing.h"

// Mode in which application will work.
enum mode{COMPRESS, DECOMPRESS, UNDEFINED};

int main(int argc, char *argv[]) {

    /*{
        char* testTab;
        __int64 testTab_size;
        file_utils::readBytesFromFile("reto.jpg", testTab, testTab_size);
        //std::cout << testTab_size * 8;

        testing::printTab(testTab, testTab_size);

        //std::string testString = std::string(testTab);

        std::string outputTestString = lz77::compressForBytes(testTab, testTab_size, 15, 15);
        file_utils::writeToFile(outputTestString, "reto.compress");

        delete []testTab;
    }*/

    /*{
        lz77_word* tab;
        __int64 tab_size = file_utils::readCompressedWordsFromFile(tab, "reto.compress");
        std::vector<char> decompressedMp3 = lz77::decompressForBytes(tab, tab_size, 512, 128);
        char* tab_c = new char[decompressedMp3.size()];

        for(__int64 i = 0; i < decompressedMp3.size(); i++)
            tab_c[i] = decompressedMp3[i];

        __int64 ss = (__int64) decompressedMp3.size();
        //std::cout << tab_c[ss - 1];

        file_utils::writeBytesToFile("reto2.jpg", tab_c, ss);

        delete []tab_c;
    }*/

    /*{
        std::fstream file("test.byt", std::ios::binary | std::ios::out);

        __int64 a = 127, b = 18;
        int c = 3;
        char *t = new char[8];
        memcpy(t, &a, 8);
        file.write(t, 8);
        memcpy(t, &b, 8);
        file.write(t, 8);
        memcpy(t, &c, 4);
        file.write(t, 4);

        file.close();

        delete []t;
    }*/

    /*{
        lz77_word a{128, 17, 'a'};
        lz77_word b{36247, 13482, 'h'};

        std::vector<lz77_word> vec{a, b};

        file_utils::writeCompressedByteWordsToFile("test.byt", vec);

    }*/

    /*{

        std::vector<lz77_word> vec = file_utils::readCompressedByteWordsFromFile("test.byt");

        for(const lz77_word word : vec)
            std::cout << word.P << " " << word.C << " " << word.S << std::endl;

    }*/

    /*{
        char *tab;
        __int64 tab_size;
        file_utils::readBytesFromFile("testy.txt", tab, tab_size);

        std::vector<lz77_word> words = lz77::compressForBytes(tab, tab_size, 15, 15);
        file_utils::writeCompressedByteWordsToFile("reto.compress", words);
    }*/

    /*{
        std::vector<lz77_word> words = file_utils::readCompressedByteWordsFromFile("reto.compress");
        std::vector<char> data = lz77::decompressForBytes(words, 15, 15);
        file_utils::writeBytesToFile("l.txt", data);
    }*/

    std::cout << std::endl << std::endl;

    // For logging purpose.
    std::string info;

    // Parameters
    mode app_mode = mode::UNDEFINED;
    std::string input_filename, output_filename;
    __int64 lookahead_buffer_size, search_buffer_size;

    // If there is no arg, printing instruction.
    if(argc <= 1){
        std::cout << "Parameters for lz77compressor: " << std::endl;
        std::cout << "    -i  -  Input file name." << std::endl;
        std::cout << "    -o  -  Output file name." << std::endl;
        std::cout << "    -t  -  Choosing application mode (compress or 'c' / decompress or 'd')." << std::endl;
        std::cout << "    -n  -  Size of look ahead buffer (>0)." << std::endl;
        std::cout << "    -k  -  Size of search buffer (>0)." << std::endl;
        return 0;
    }

    // Iterating on every arg.
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
            lookahead_buffer_size = strtoll(argv[i], nullptr, 10);
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
            search_buffer_size = strtoll(argv[i], nullptr, 10);
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


    // Checking if input file exists.
    std::ifstream input_file(input_filename);
    if(!input_file.good()){
        info = "File \"";
        info += input_filename;
        info += "\" doesn't exist.";
        logger::info(info);
        return 0;
    }
    input_file.close();

    // Compressing file.
    if(app_mode == mode::COMPRESS){
        logger::info("Starting compression.");

        char *tab;
        __int64 tab_size;
        file_utils::readBytesFromFile(input_filename, tab, tab_size);
        //std::cout << "LA: " << lookahead_buffer_size << std::endl;
        std::vector<lz77_word> words = lz77::compressForBytes(tab, tab_size, lookahead_buffer_size, search_buffer_size);

        std::cout << "Wypisanie: " << std::endl;
        for(lz77_word w : words){
            std::cout << w.P << " " << w.C << " " << w.S << std::endl;
        }

        file_utils::writeCompressedByteWordsToFile(output_filename, words);

        logger::info("Successfully compressed!");
        return 0;
    }

    // Decompressing file.
    logger::info("Starting decompression.");

    std::vector<lz77_word> words = file_utils::readCompressedByteWordsFromFile(input_filename);
    std::vector<char> data = lz77::decompressForBytes(words, lookahead_buffer_size, search_buffer_size);
    file_utils::writeBytesToFile(output_filename, data);

    logger::info("Successfully decompressed!");

    return 0;
}
