
ifndef PREFIX
$(error PREFIX symbol undefined)
endif

ifndef VERSION
$(error VERSION symbol undefined)
endif

all:		wError.pc

%.pc:		%.pc.template
		@echo "[ SED ] $@"
		@sed -e 's:##PREFIX##:$(PREFIX):' -e 's/##VERSION##/$(VERSION)/' $< > $@

clean:
		@echo "[CLEAN]"
		@rm -fv wError.pc

cleanall:	clean
