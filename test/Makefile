EXE := "./before_main.exe"
OBJS += $(patsubst ./%.cpp,./%.opp,$(wildcard ./*.cpp))

.PHONY: all clean
all: $(EXE)

$(EXE): $(OBJS) $(LIB)
	@echo 'Linking source file(s) $(OBJS) together into $@...'
	@$(CXX) -o "$@" $(OBJS)
	@echo "Built $@"

# Build cpp
./%.opp: ./%.cpp 
	@echo 'Building source file $<...'
	@$(CXX) --std=c++20 -g -c -Wall -fpic -o  "$@" "$<" 
	@echo 'Built $@'
	@echo

clean:
	@rm -rf ./*.o* ./*.exe
	@echo "All clean!"

outputs:
	@echo $(OBJS) $(EXE)


run: $(EXE)
	$(EXE)