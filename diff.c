	die("bad config variable '%s'", var);
static int count_lines(const char *data, int size)
{
	int count, ch, completely_empty = 1, nl_just_seen = 0;
	count = 0;
	while (0 < size--) {
		ch = *data++;
		if (ch == '\n') {
			count++;
			nl_just_seen = 1;
			completely_empty = 0;
		}
		else {
			nl_just_seen = 0;
			completely_empty = 0;
		}
	}
	if (completely_empty)
		return 0;
	if (!nl_just_seen)
		count++; /* no trailing newline */
	return count;
}

static void copy_file_with_prefix(FILE *file,
				  int prefix, const char *data, int size,
				  const char *set, const char *reset)
	int ch, nl_just_seen = 1;
	while (0 < size--) {
		ch = *data++;
		if (nl_just_seen) {
			fputs(set, file);
			putc(prefix, file);
		if (ch == '\n') {
			nl_just_seen = 1;
			fputs(reset, file);
		} else
			nl_just_seen = 0;
		putc(ch, file);
	if (!nl_just_seen)
		fprintf(file, "%s\n\\ No newline at end of file\n", reset);
	const char *old = diff_get_color(color_diff, DIFF_FILE_OLD);
	const char *new = diff_get_color(color_diff, DIFF_FILE_NEW);
		copy_file_with_prefix(o->file, '-', data_one, size_one, old, reset);
		copy_file_with_prefix(o->file, '+', data_two, size_two, new, reset);
}

static int fill_mmfile(mmfile_t *mf, struct diff_filespec *one)
{
	if (!DIFF_FILE_VALID(one)) {
		mf->ptr = (char *)""; /* does not matter */
		mf->size = 0;
		return 0;
	}
	else if (diff_populate_filespec(one, 0))
		return -1;

	mf->ptr = one->data;
	mf->size = one->size;
	return 0;
	xdemitcb_t ecb;
	xpp.flags = XDF_NEED_MINIMAL;
		      &xpp, &xecfg, &ecb);
typedef unsigned long (*sane_truncate_fn)(char *line, unsigned long len);

struct emit_callback {
	int nparents, color_diff;
	unsigned ws_rule;
	sane_truncate_fn truncate;
	const char **label_path;
	struct diff_words_data *diff_words;
	int *found_changesp;
	FILE *file;
};
		/* flush buffers */
		if (ecbdata->diff_words->minus.text.size ||
				ecbdata->diff_words->plus.text.size)
			diff_words_show(ecbdata->diff_words);

static void emit_line(FILE *file, const char *set, const char *reset, const char *line, int len)
{
	int has_trailing_newline, has_trailing_carriage_return;

	has_trailing_newline = (len > 0 && line[len-1] == '\n');
	if (has_trailing_newline)
		len--;
	has_trailing_carriage_return = (len > 0 && line[len-1] == '\r');
	if (has_trailing_carriage_return)
		len--;

	fputs(set, file);
	fwrite(line, len, 1, file);
	fputs(reset, file);
	if (has_trailing_carriage_return)
		fputc('\r', file);
	if (has_trailing_newline)
		fputc('\n', file);
}

static void emit_add_line(const char *reset, struct emit_callback *ecbdata, const char *line, int len)
{
	const char *ws = diff_get_color(ecbdata->color_diff, DIFF_WHITESPACE);
	const char *set = diff_get_color(ecbdata->color_diff, DIFF_FILE_NEW);

	if (!*ws)
		emit_line(ecbdata->file, set, reset, line, len);
	else {
		/* Emit just the prefix, then the rest. */
		emit_line(ecbdata->file, set, reset, line, ecbdata->nparents);
		ws_check_emit(line + ecbdata->nparents,
			      len - ecbdata->nparents, ecbdata->ws_rule,
			      ecbdata->file, set, reset, ws);
	}
}

	int i;
	int color;
	/* This is not really necessary for now because
	 * this codepath only deals with two-way diffs.
	 */
	for (i = 0; i < len && line[i] == '@'; i++)
		;
	if (2 <= i && i < len && line[i] == ' ') {
		ecbdata->nparents = i - 1;
		emit_line(ecbdata->file,
			  diff_get_color(ecbdata->color_diff, DIFF_FRAGINFO),
			  reset, line, len);
	if (len < ecbdata->nparents) {
	color = DIFF_PLAIN;
	if (ecbdata->diff_words && ecbdata->nparents != 1)
		/* fall back to normal diff */
		free_diff_words_data(ecbdata);
		if (ecbdata->diff_words->minus.text.size ||
		    ecbdata->diff_words->plus.text.size)
			diff_words_show(ecbdata->diff_words);
	for (i = 0; i < ecbdata->nparents && len; i++) {
		if (line[i] == '-')
			color = DIFF_FILE_OLD;
		else if (line[i] == '+')
			color = DIFF_FILE_NEW;
	}
	if (color != DIFF_FILE_NEW) {
		emit_line(ecbdata->file,
			  diff_get_color(ecbdata->color_diff, color),
			  reset, line, len);
		return;
	emit_add_line(reset, ecbdata, line, len);
		unsigned int added, deleted;
	int max_change = 0, max_len = 0;
		int change = file->added + file->deleted;
		int added = data->files[i]->added;
		int deleted = data->files[i]->deleted;
			fprintf(options->file, "%s%d%s", del_c, deleted, reset);
			fprintf(options->file, "%s%d%s", add_c, added, reset);
		fprintf(options->file, "%5d%s", added + deleted,
static void show_shortstats(struct diffstat_t* data, struct diff_options *options)
				"%d\t%d\t", file->added, file->deleted);
	int trailing_blanks_start;
static int is_conflict_marker(const char *line, unsigned long len)
	if (len < 8)
	case '=': case '>': case '<':
	for (cnt = 1; cnt < 7; cnt++)
	/* line[0] thru line[6] are same as firstchar */
	if (firstchar == '=') {
		/* divider between ours and theirs? */
		if (len != 8 || line[7] != '\n')
			return 0;
	} else if (len < 8 || !isspace(line[7])) {
		/* not divider before ours nor after theirs */
	}
		if (!ws_blank_line(line + 1, len - 1, data->ws_rule))
			data->trailing_blanks_start = 0;
		else if (!data->trailing_blanks_start)
			data->trailing_blanks_start = data->lineno;
		if (is_conflict_marker(line + 1, len - 1)) {
		data->trailing_blanks_start = 0;
		data->trailing_blanks_start = 0;
	fprintf(o->file, "%sdiff --git %s %s%s\n", set, a_one, b_two, reset);
		fprintf(o->file, "%snew file mode %06o%s\n", set, two->mode, reset);
		if (xfrm_msg && xfrm_msg[0])
			fprintf(o->file, "%s%s%s\n", set, xfrm_msg, reset);
		fprintf(o->file, "%sdeleted file mode %06o%s\n", set, one->mode, reset);
		if (xfrm_msg && xfrm_msg[0])
			fprintf(o->file, "%s%s%s\n", set, xfrm_msg, reset);
			fprintf(o->file, "%sold mode %06o%s\n", set, one->mode, reset);
			fprintf(o->file, "%snew mode %06o%s\n", set, two->mode, reset);
		if (xfrm_msg && xfrm_msg[0])
			fprintf(o->file, "%s%s%s\n", set, xfrm_msg, reset);
		    !memcmp(mf1.ptr, mf2.ptr, mf1.size))
		xdemitcb_t ecb;
		xpp.flags = XDF_NEED_MINIMAL | o->xdl_opts;
			      &xpp, &xecfg, &ecb);
		xdemitcb_t ecb;
		xpp.flags = XDF_NEED_MINIMAL | o->xdl_opts;
			      &xpp, &xecfg, &ecb);
		xdemitcb_t ecb;
		xpp.flags = XDF_NEED_MINIMAL;
			      &xpp, &xecfg, &ecb);

		if ((data.ws_rule & WS_TRAILING_SPACE) &&
		    data.trailing_blanks_start) {
			fprintf(o->file, "%s:%d: ends with blank lines.\n",
				data.filename, data.trailing_blanks_start);
			data.status = 1; /* report errors */
	if (ce->ce_flags & CE_VALID)
	char *data = xmalloc(100);
		"Subproject commit %s\n", sha1_to_hex(s->sha1));
	retval = run_command_v_opt(spawn_arg, 0);
			  struct diff_filepair *p)
		strbuf_addf(msg, "similarity index %d%%", similarity_index(p));
		strbuf_addstr(msg, "\ncopy from ");
		strbuf_addstr(msg, "\ncopy to ");
		strbuf_addch(msg, '\n');
		strbuf_addf(msg, "similarity index %d%%", similarity_index(p));
		strbuf_addstr(msg, "\nrename from ");
		strbuf_addstr(msg, "\nrename to ");
		strbuf_addch(msg, '\n');
			strbuf_addf(msg, "dissimilarity index %d%%\n",
				    similarity_index(p));
		/* nothing */
		;
		strbuf_addf(msg, "index %.*s..%.*s",
		strbuf_addch(msg, '\n');
	if (msg->len)
		strbuf_setlen(msg, msg->len - 1);

	if (msg) {
		fill_metainfo(msg, name, other, one, two, o, p);
		xfrm_msg = msg->len ? msg->buf : NULL;
	}
			     one, two, xfrm_msg, o, complete_rewrite);
	if (DIFF_OPT_TST(options, QUIET)) {
		DIFF_OPT_SET(options, QUIET);
	for(;;) {
	    !hashcmp(one->sha1, two->sha1))
		xdemitcb_t ecb;
		xpp.flags = XDF_NEED_MINIMAL;
			      &xpp, &xecfg, &ecb);
		 * 1. Entries that come from stat info dirtyness
	if (diff_queued_diff.nr)
		    const char *concatpath)
	if (addremove != '-')
	DIFF_OPT_SET(options, HAS_CHANGES);
		 const char *concatpath)
	DIFF_OPT_SET(options, HAS_CHANGES);
	if (start_command(&child) != 0 ||
	    strbuf_read(&buf, child.out, 0) < 0 ||
	    finish_command(&child) != 0) {
		close(child.out);
		error("error running textconv command '%s'", pgm);
	close(child.out);