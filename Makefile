.PHONY: clean All

All:
	@echo "----------Building project:[ mpi-dot - Debug ]----------"
	@cd "mpi-dot" && "$(MAKE)" -f  "mpi-dot.mk"
clean:
	@echo "----------Cleaning project:[ mpi-dot - Debug ]----------"
	@cd "mpi-dot" && "$(MAKE)" -f  "mpi-dot.mk" clean
