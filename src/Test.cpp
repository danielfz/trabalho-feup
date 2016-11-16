#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "Feup.h"

void test1() {
    std::cout << "test1\n";
    Feup feup("../resources/mieic.csv","../resources/pessoas.csv");
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s;
	s.push_back(CUTE(test1));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
    std::cout << "tests\n";
    auto runner = cute::makeRunner(lis,argc,argv);
	bool success = runner(s,"AllTests");

    //test1();
    return success;
}


