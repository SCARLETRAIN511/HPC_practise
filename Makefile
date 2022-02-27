.PHONY: clean All

All:
	@echo "----------Building project:[ mpi-ssend - Debug ]----------"
	@cd "mpi-ssend" && "$(MAKE)" -f  "mpi-ssend.mk"
clean:
	@echo "----------Cleaning project:[ mpi-ssend - Debug ]----------"
	@cd "mpi-ssend" && "$(MAKE)" -f  "mpi-ssend.mk" clean
