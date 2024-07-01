TOPDIR := ../../
include $(TOPDIR)build/core/config.mak

CFLAGS += -I./

CXXFLAGS += -I./

GOAL = send_file

OBJS += send.o

.PHONY: all
all: $(GOAL)
	$(MSG_SPLIT_LINE)
	@$(MKDIR) -p $(PROJECT_DIR)/system/bin
	@$(CP) -u $(GOAL) $(PROJECT_DIR)/system/bin/$(GOAL)

$(GOAL): $(OBJS)
	$(MSG_SPLIT_LINE)
	$(MSG_LINKING)
	$(TARGET_CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)
	$(MSG_GOAL_OK)

.PHONY: clean
clean:
	$(MSG_SPLIT_LINE)
	$(RM) -rf $(GOAL) $(OBJS) $(OBJS:.o=.d)
	$(RM) -f $(PRODUCT_DIR)/system/app/$(GOAL)

-include $(OBJS:.o=.d)
