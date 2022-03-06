.PHONY: clean All

All:
	@echo "----------Building project:[ 03-lapack - Debug ]----------"
	@cd "03-lapack" && "$(MAKE)" -f  "03-lapack.mk"
clean:
	@echo "----------Cleaning project:[ 03-lapack - Debug ]----------"
	@cd "03-lapack" && "$(MAKE)" -f  "03-lapack.mk" clean
