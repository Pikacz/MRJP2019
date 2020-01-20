rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

OUTPUT=.build

OPT=-O3

LATTE_DIRS=$(dir $(call rwildcard,Latte,*))

TESTS_DIRS=$(dir $(call rwildcard,Tests,*))
TESTS_HPPS=$(call rwildcard,Tests,*.hpp)

TESTS_CPPS=$(basename $(call rwildcard,Tests/testCase,*.cpp)) $(basename $(call rwildcard,Tests/tests,*.cpp))
TESTS_OBJS=$(addprefix $(OUTPUT)/, $(addsuffix .o, $(TESTS_CPPS)))


LOGIC_DIRS=$(dir $(call rwildcard,Logic,*))
LOGIC_HPPS=$(call rwildcard,Logic,*.hpp)
LOGIC_OBJS=$(addprefix $(OUTPUT)/, $(addsuffix .o, $(basename $(call rwildcard,Logic,*.cpp))))


ANTLR_DIRS=$(dir $(call rwildcard,antlr4-runtime,*))
ANTLR_HS=$(call rwildcard,antlr4-runtime,*.h)
ANTLR_OBJS=$(addprefix $(OUTPUT)/, $(addsuffix .o, $(basename $(call rwildcard,antlr4-runtime,*.cpp))))


BUILD_DIRS=$(addprefix $(OUTPUT)/, $(LOGIC_DIRS) $(ANTLR_DIRS) $(TESTS_DIRS) $(LATTE_DIRS))


all: tests

tests: $(ANTLR_OBJS) $(LOGIC_OBJS) $(TESTS_OBJS) Logic/Logic.hpp antlr4-runtime/antlr4_runtime.hpp $(ANTLR_HS) $(LOGIC_HPPS) $(TESTS_HPPS)
	@echo "compiling Tests"

	@clang++ -std=c++17 $(OPT) Tests/main.cpp $(ANTLR_OBJS) $(LOGIC_OBJS) $(TESTS_OBJS) -I antlr4-runtime/ -I Logic/ -I antlr4-runtime/src/ -I Tests/ -o tests_bin

clean:
	rm -rf $(OUTPUT)


$(OUTPUT)/Tests/%.o: Tests/%.cpp $(OUTPUT) Logic/Logic.hpp antlr4-runtime/antlr4_runtime.hpp $(ANTLR_HS) $(LOGIC_HPPS) $(TESTS_HPPS)
	clang++ -std=c++17 $(OPT) -c -o $@ $< -I antlr4-runtime/ -I Logic/ -I antlr4-runtime/src/ -I Tests/

$(OUTPUT)/Logic/%.o: Logic/%.cpp $(OUTPUT) antlr4-runtime/antlr4_runtime.hpp $(ANTLR_HS) $(LOGIC_HPPS)
	clang++ -std=c++17 $(OPT) -c -o $@ $< -I antlr4-runtime/ -I Logic/ -I antlr4-runtime/src/

$(OUTPUT)/antlr4-runtime/%.o : antlr4-runtime/%.cpp $(OUTPUT) $(ANTLR_HS)
	clang++ -std=gnu++14 $(OPT) -c -o $@ $< -I antlr4-runtime/src/


$(OUTPUT):
	@mkdir -p $(BUILD_DIRS)
