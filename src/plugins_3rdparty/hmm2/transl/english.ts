<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="en_US">
<context>
    <name>HMMBuildDialog</name>
    <message>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="32"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="49"/>
        <source>...</source>
        <translation>...</translation>
    </message>
    <message>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="14"/>
        <source>HMM Build</source>
        <translation>HMM Build</translation>
    </message>
    <message>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="22"/>
        <source>Multiple alignment file:</source>
        <translation>Multiple alignment file:</translation>
    </message>
    <message>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="39"/>
        <source>result_hmm_label</source>
        <translation>File to save HMM profile:</translation>
    </message>
    <message>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="58"/>
        <source>expert_options</source>
        <translation>Expert options</translation>
    </message>
    <message>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="79"/>
        <source>name</source>
        <translation>Name this HMM:</translation>
    </message>
    <message>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="108"/>
        <source>default_hmmls</source>
        <translation>Default (hmmls) behaviour:</translation>
    </message>
    <message>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="156"/>
        <source>multi_domain_hmmfs</source>
        <translation>Emulate hmmfs behaviour:</translation>
    </message>
    <message>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="201"/>
        <source>single_global_hmms</source>
        <translation>Emulate hmms behaviour:</translation>
    </message>
    <message>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="240"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="243"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="246"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="266"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="269"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="272"/>
        <source>single_local_hmmsw</source>
        <translation>Emulate hmmsw behaviour:</translation>
    </message>
    <message>
        <source>ok_button</source>
        <translation type="obsolete">Build</translation>
    </message>
    <message>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="70"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="73"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="76"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="86"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="89"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="92"/>
        <source>name_tip</source>
        <translation>Name can be any string of non-whitespace characters (e.g. one ”word”). </translation>
    </message>
    <message>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="99"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="102"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="105"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="128"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="131"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="134"/>
        <source>default_hmmls_tip</source>
        <translation>By default, the model is configured to find one or more nonoverlapping alignments to the complete model:
multiple global alignments with respect to the model, and local with respect to the sequence</translation>
    </message>
    <message>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="147"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="150"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="153"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="176"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="179"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="182"/>
        <source>multi_domain_hmmfs_tip</source>
        <translation>Configure the model for finding multiple domains per sequence, where each domain can be a local (fragmentary) alignment.
This is analogous to the old hmmfs program of HMMER 1.</translation>
    </message>
    <message>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="192"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="195"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="198"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="221"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="224"/>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="227"/>
        <source>single_global_hmms_tip</source>
        <translation>Configure the model for finding a single global alignment to a target sequence,
analogous to the old hmms program of HMMER 1.</translation>
    </message>
    <message>
        <location filename="../src/u_build/ui/HMMBuildDialog.ui" line="237"/>
        <source>single_local_hmmsw_tip</source>
        <translation>Configure the model for finding a single local alignment per target sequence. 
This is analogous to the standard Smith/Waterman algorithm or the hmmsw program of HMMER 1.</translation>
    </message>
    <message>
        <source>close_button</source>
        <translation type="obsolete">Close</translation>
    </message>
</context>
<context>
    <name>HMMBuildWorker</name>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="89"/>
        <source>Fixed tip</source>
        <translation type="unfinished">Fix the length of the random sequences to &lt;n&gt;, where &lt;n&gt; is a positive (and reasonably sized) integer. 
The default is instead to generate sequences with a variety of different lengths, controlled by a Gaussian (normal) distribution.</translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="91"/>
        <source>mean_tip_1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="93"/>
        <source>num_tip_1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="95"/>
        <source>sd_tip_1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="97"/>
        <source>seed_tip_1</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>HMMCalibrateDialog</name>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="22"/>
        <source>HMM file: </source>
        <translation>HMM file: </translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="32"/>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="348"/>
        <source>...</source>
        <translation>...</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="41"/>
        <source>expert_options</source>
        <translation>Expert options</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="107"/>
        <source>mean</source>
        <translation>Mean length of the synthetic sequences:</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="158"/>
        <source>num_tip_tool</source>
        <translation type="unfinished">Number of synthetic sequences.
 If &lt;n&gt; is less than about 1000, the fit to the EVD may fail
Higher numbers of &lt;n&gt; will give better determined EVD parameters. 
The default is 5000; it was empirically chosen as a tradeoff between accuracy and computation time.</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="161"/>
        <source>num_tip_status</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="164"/>
        <source>num_tip_whats</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="167"/>
        <source>num</source>
        <translation>Number of synthetic sequences:</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="193"/>
        <source>num_tip_tool_1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="196"/>
        <source>num_tip_status_1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="199"/>
        <source>num_tip_whats_1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="218"/>
        <source>sd_tip_tool</source>
        <translation type="unfinished">Standard deviation of the synthetic sequence length.
A positive number. The default is 200. 
Note that the Gaussian is left-truncated so that no sequences have lengths &lt;= 0.</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="221"/>
        <source>sd_tip_status</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="224"/>
        <source>sd_tip_whats</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="227"/>
        <source>sd</source>
        <translation>Standard deviation:</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="247"/>
        <source>sd_tip_1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="281"/>
        <source>seed</source>
        <translation>Random seed:</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="56"/>
        <source>fixed</source>
        <translation>Fix the length of the random sequences to:</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="14"/>
        <source>HMM Calibrate</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="323"/>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="335"/>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="338"/>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="341"/>
        <source>output_file_name</source>
        <translation>Save calibrated profile to file:</translation>
    </message>
    <message>
        <source>ok_button</source>
        <translation type="obsolete">Calibrate</translation>
    </message>
    <message>
        <source>hmmcalibrate_dialog_title</source>
        <translation type="obsolete">HMM Calibrate</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="53"/>
        <source>Fixed tip</source>
        <translation>Fix the length of the random sequences to &lt;n&gt;, where &lt;n&gt; is a positive (and reasonably sized) integer. 
The default is instead to generate sequences with a variety of different lengths, controlled by a Gaussian (normal) distribution.</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="98"/>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="101"/>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="104"/>
        <source>Mean length of the synthetic sequences, positive real number. The default value is 325.</source>
        <translation>Mean length of the synthetic sequences, positive real number. The default value is 325.</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="133"/>
        <source>mean_tip_tool</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="136"/>
        <source>mean_tip_status</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="139"/>
        <source>mean_tip_whats</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>sd_tip</source>
        <translation type="obsolete">Standard deviation of the synthetic sequence length.
A positive number. The default is 200. 
Note that the Gaussian is left-truncated so that no sequences have lengths &lt;= 0.</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="272"/>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="275"/>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="278"/>
        <location filename="../src/u_calibrate/ui/HMMCalibrateDialog.ui" line="301"/>
        <source>seed_tip</source>
        <translation>The random seed, where &lt;n&gt; is a positive integer. 
The default is to use time() to generate a different seed for each run, 
which means that two different runs of hmmcalibrate on the same HMM will give slightly different results. 
You can use this option to generate reproducible results for different hmmcalibrate runs on the same HMM.</translation>
    </message>
    <message>
        <source>close_button</source>
        <translation type="obsolete">Close</translation>
    </message>
</context>
<context>
    <name>HMMSearchDialog</name>
    <message>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="23"/>
        <source>HMM Search</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="37"/>
        <source>File with HMM profile:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="47"/>
        <source>...</source>
        <translation>...</translation>
    </message>
    <message>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="62"/>
        <source>Expert options</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="77"/>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="80"/>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="83"/>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="226"/>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="229"/>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="232"/>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="75"/>
        <source>E-value filtering can be used to exclude low-probability hits from result.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="86"/>
        <source>Filter results with E-value greater then:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="119"/>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="122"/>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="125"/>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="135"/>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="138"/>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="141"/>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="76"/>
        <source>Score based filtering is an alternative to E-value filtering to exclude low-probability hits from result.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="128"/>
        <source>Filter results with Score lower than:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="188"/>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="191"/>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="194"/>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="210"/>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="213"/>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="216"/>
        <source>Calculate the E-value scores as if we had seen a sequence database of &lt;n&gt; sequences.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="219"/>
        <source>Number of sequences in dababase:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="277"/>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="280"/>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="283"/>
        <source>Variants of algorithm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>hmm_search_dialog_title</source>
        <translation type="obsolete">HMM search</translation>
    </message>
    <message>
        <source>hmm_file</source>
        <translation type="obsolete">File with HMM profile:</translation>
    </message>
    <message>
        <source>expert_box_title</source>
        <translation type="obsolete">Expert options</translation>
    </message>
    <message>
        <source>e_value_as_n_seq</source>
        <translation type="obsolete">Number of sequences in dababase:</translation>
    </message>
    <message>
        <source>ok_button</source>
        <translation type="obsolete">Search</translation>
    </message>
    <message>
        <source>e_value_as_nsec_tip</source>
        <translation type="obsolete">Calculate the E-value scores as if we had seen a sequence database of &lt;n&gt; sequences.</translation>
    </message>
    <message>
        <source>close_button</source>
        <translation type="obsolete">Close</translation>
    </message>
    <message>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="241"/>
        <source>1E</source>
        <translation>1e</translation>
    </message>
    <message>
        <source>results_evalue_cutoff</source>
        <translation type="obsolete">Filter results with E-value greater then:</translation>
    </message>
    <message>
        <source>results_score_cutoff_tip</source>
        <translation type="obsolete">Score based filtering is an alternative to E-value filtering to exclude low-probability hits from result.</translation>
    </message>
    <message>
        <source>results_score_cutoff</source>
        <translation type="obsolete">Filter results with Score lower than:</translation>
    </message>
    <message>
        <source>results_evalue_cutoff_tip</source>
        <translation type="obsolete">E-value filtering can be used to exclude low-probability hits from result.</translation>
    </message>
    <message>
        <source>algo_combo_tip</source>
        <translation type="obsolete">Variants of algorithm</translation>
    </message>
    <message>
        <location filename="../src/u_search/ui/HMMSearchDialog.ui" line="257"/>
        <source>Algorithm</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="74"/>
        <source>Calculate the E-value scores as if we had seen a sequence database of &amp;lt;n&amp;gt; sequences.</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <location filename="../src/HMMIOWorker.cpp" line="68"/>
        <source>HMM Profile</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>U2::GTest_uHMMERCalibrate</name>
    <message>
        <location filename="../src/u_tests/uhmmerTests.cpp" line="569"/>
        <source>uhmmer-calibrate-subtask</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::HMM2QDActor</name>
    <message>
        <location filename="../src/u_search/HMMSearchQDActor.cpp" line="65"/>
        <location filename="../src/u_search/HMMSearchQDActor.cpp" line="150"/>
        <source>HMM2</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchQDActor.cpp" line="76"/>
        <source>QD HMM2 search</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchQDActor.cpp" line="82"/>
        <source>Power of e-value must be less or equal to zero. Using default value: 1e-1</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchQDActor.cpp" line="151"/>
        <source>Searches HMM signals in a sequence with one or more profile HMM2 and saves the results as annotations.</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchQDActor.cpp" line="157"/>
        <source>Profile HMM</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchQDActor.cpp" line="158"/>
        <source>Semicolon-separated list of input HMM files.</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchQDActor.cpp" line="161"/>
        <source>Min Length</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchQDActor.cpp" line="162"/>
        <source>Minimum length of a result region.</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchQDActor.cpp" line="165"/>
        <source>Max Length</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchQDActor.cpp" line="166"/>
        <source>Maximum length of a result region.</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchQDActor.cpp" line="169"/>
        <source>Filter by High E-value</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchQDActor.cpp" line="170"/>
        <source>Reports domains &amp;lt;= this E-value threshold in output.</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchQDActor.cpp" line="174"/>
        <source>Filter by Low Score</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchQDActor.cpp" line="175"/>
        <source>Reports domains &amp;gt;= this score cutoff in output.</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchQDActor.cpp" line="178"/>
        <source>Number of Sequences</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchQDActor.cpp" line="179"/>
        <source>Specifies number of significant sequences. It is used for domain E-value calculations.</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::HMMADVContext</name>
    <message>
        <location filename="../src/uHMMPlugin.cpp" line="260"/>
        <source>Search with HMM model...</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/uHMMPlugin.cpp" line="277"/>
        <source>error</source>
        <translation>Error!</translation>
    </message>
    <message>
        <location filename="../src/uHMMPlugin.cpp" line="277"/>
        <source>no_sequence_found</source>
        <translation>No sequences found</translation>
    </message>
</context>
<context>
    <name>U2::HMMBuildDialogController</name>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="112"/>
        <source>incorrect_ali_file</source>
        <translation>Incorrect alignment file!</translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="117"/>
        <source>incorrect_hmm_file</source>
        <translation>Incorrect HMM file!</translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="133"/>
        <source>error</source>
        <translation>Error!</translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="142"/>
        <source>starting_build_process</source>
        <translation>Starting build process</translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="145"/>
        <source>back_button</source>
        <translation>Hide</translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="169"/>
        <source>build_finished_with_errors_%1</source>
        <translation>HMM build finished with errors: %1</translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="173"/>
        <source>build_finished_successfuly</source>
        <translation>HMM build finished successfuly!</translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="175"/>
        <source>ok_button</source>
        <translation>Build</translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="185"/>
        <source>progress_%1%</source>
        <translation>Progress: %1%</translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="146"/>
        <source>cancel_button</source>
        <translation>Cancel</translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="176"/>
        <source>close_button</source>
        <translation>Close</translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="171"/>
        <source>build_canceled</source>
        <translation>HMM build canceled</translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="58"/>
        <source>Build</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="59"/>
        <source>Close</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="80"/>
        <source>select_file_with_alignment</source>
        <translation>Select file with alignment</translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="92"/>
        <source>Select file with HMM profile</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::HMMBuildTask</name>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="342"/>
        <source>multiple_alignment_is_empty</source>
        <translation>Multiple alignment is empty</translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="346"/>
        <source>multiple_alignment_is_0_len</source>
        <translation>Multiple alignment is of 0 length</translation>
    </message>
    <message>
        <source>miltiple_alignment_is_not_consistent</source>
        <translation type="obsolete">Multiple alignment is not consistent</translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="351"/>
        <source>only_amino_and_nucl_alphabets_are_supported</source>
        <translation>Invalid alphabet! Only amino and nucleic alphabets are supported</translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="359"/>
        <source>error_creating_msa</source>
        <translation>Error creating MSA structure</translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="325"/>
        <source>Build HMM profile &apos;%1&apos;</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::HMMBuildToFileTask</name>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="256"/>
        <source>alignment_object_not_found</source>
        <translation>Alignment object not found!</translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="310"/>
        <source>none</source>
        <translation>none</translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="209"/>
        <source>input_format_error</source>
        <translation>Error reading alignment file</translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="196"/>
        <source>Build HMM profile &apos;%1&apos; -&gt; &apos;%2&apos;</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="226"/>
        <source>Build HMM profile to &apos;%1&apos;</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="251"/>
        <source>Incorrect input file</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="298"/>
        <source>Source alignment</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="299"/>
        <source>Profile name</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="301"/>
        <source>Task was not finished</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="306"/>
        <source>Profile file</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildDialogController.cpp" line="307"/>
        <source>Expert options</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::HMMCalibrateDialogController</name>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateDialogController.cpp" line="65"/>
        <location filename="../src/u_calibrate/HMMCalibrateDialogController.cpp" line="74"/>
        <source>select_file_with_hmm_model</source>
        <translation>Select file with HMM model</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateDialogController.cpp" line="95"/>
        <source>illegal_in_file_name</source>
        <translation>Incorrect HMM file!</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateDialogController.cpp" line="101"/>
        <source>illegal fixed value</source>
        <translation>Illegal fixed length value!</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateDialogController.cpp" line="118"/>
        <source>illegal_out_file_name</source>
        <translation>Invalid output file name</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateDialogController.cpp" line="124"/>
        <source>error</source>
        <translation>Error!</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateDialogController.cpp" line="134"/>
        <source>starting_calibration_process</source>
        <translation>Starting calibration process</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateDialogController.cpp" line="137"/>
        <source>back_button</source>
        <translation>Hide</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateDialogController.cpp" line="154"/>
        <source>calibration_finished_with_errors_%1</source>
        <translation>Calibration finished with errors: %1</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateDialogController.cpp" line="158"/>
        <source>calibration_finished_successfuly</source>
        <translation>Calibration finished successfuly!</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateDialogController.cpp" line="160"/>
        <source>ok_button</source>
        <translation>Calibrate</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateDialogController.cpp" line="168"/>
        <source>progress_%1%</source>
        <translation>Progress: %1%</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateDialogController.cpp" line="138"/>
        <source>cancel_button</source>
        <translation>Cancel</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateDialogController.cpp" line="51"/>
        <source>Calibrate</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateDialogController.cpp" line="52"/>
        <source>Close</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateDialogController.cpp" line="161"/>
        <source>close_button</source>
        <translation>Close</translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateDialogController.cpp" line="156"/>
        <source>calibration_canceled</source>
        <translation>Calibration was cancelled</translation>
    </message>
</context>
<context>
    <name>U2::HMMCalibrateParallelSubTask</name>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateTask.cpp" line="137"/>
        <source>Parallel HMM calibration subtask</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::HMMCalibrateParallelTask</name>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateTask.cpp" line="35"/>
        <source>HMM calibrate &apos;%1&apos;</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::HMMCalibrateTask</name>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateTask.cpp" line="17"/>
        <source>HMM calibrate &apos;%1&apos;</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::HMMCalibrateToFileTask</name>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateTask.cpp" line="161"/>
        <source>HMM calibrate &apos;%1&apos;</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateTask.cpp" line="200"/>
        <source>Source profile</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateTask.cpp" line="203"/>
        <source>Task was not finished</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateTask.cpp" line="208"/>
        <source>Result profile</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateTask.cpp" line="209"/>
        <source>Expert options</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateTask.cpp" line="211"/>
        <source>Number of random sequences to sample</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateTask.cpp" line="212"/>
        <source>Random number seed</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateTask.cpp" line="213"/>
        <source>Mean of length distribution</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateTask.cpp" line="214"/>
        <source>Standard deviation of length distribution</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateTask.cpp" line="216"/>
        <source>Calculated evidence (mu , lambda)</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::HMMCreateWPoolTask</name>
    <message>
        <location filename="../src/u_calibrate/HMMCalibrateTask.cpp" line="98"/>
        <source>Initialize parallel context</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::HMMIO</name>
    <message>
        <location filename="../src/HMMIO.cpp" line="215"/>
        <location filename="../src/HMMIO.cpp" line="231"/>
        <location filename="../src/HMMIO.cpp" line="391"/>
        <location filename="../src/HMMIO.cpp" line="397"/>
        <location filename="../src/HMMIO.cpp" line="423"/>
        <location filename="../src/HMMIO.cpp" line="454"/>
        <location filename="../src/HMMIO.cpp" line="479"/>
        <source>illegal line</source>
        <translation>Illegal line</translation>
    </message>
    <message>
        <location filename="../src/HMMIO.cpp" line="219"/>
        <source>file_format_is_not_supported</source>
        <translation>File format is not supported</translation>
    </message>
    <message>
        <location filename="../src/HMMIO.cpp" line="248"/>
        <location filename="../src/HMMIO.cpp" line="374"/>
        <location filename="../src/HMMIO.cpp" line="378"/>
        <source>value is illegal %1</source>
        <translation>Value is illegal: %1</translation>
    </message>
    <message>
        <location filename="../src/HMMIO.cpp" line="277"/>
        <location filename="../src/HMMIO.cpp" line="282"/>
        <location filename="../src/HMMIO.cpp" line="289"/>
        <location filename="../src/HMMIO.cpp" line="294"/>
        <location filename="../src/HMMIO.cpp" line="301"/>
        <location filename="../src/HMMIO.cpp" line="306"/>
        <location filename="../src/HMMIO.cpp" line="313"/>
        <location filename="../src/HMMIO.cpp" line="319"/>
        <location filename="../src/HMMIO.cpp" line="328"/>
        <location filename="../src/HMMIO.cpp" line="333"/>
        <location filename="../src/HMMIO.cpp" line="345"/>
        <location filename="../src/HMMIO.cpp" line="354"/>
        <location filename="../src/HMMIO.cpp" line="359"/>
        <location filename="../src/HMMIO.cpp" line="403"/>
        <location filename="../src/HMMIO.cpp" line="408"/>
        <location filename="../src/HMMIO.cpp" line="412"/>
        <location filename="../src/HMMIO.cpp" line="429"/>
        <location filename="../src/HMMIO.cpp" line="433"/>
        <location filename="../src/HMMIO.cpp" line="438"/>
        <location filename="../src/HMMIO.cpp" line="445"/>
        <location filename="../src/HMMIO.cpp" line="460"/>
        <location filename="../src/HMMIO.cpp" line="469"/>
        <location filename="../src/HMMIO.cpp" line="485"/>
        <location filename="../src/HMMIO.cpp" line="493"/>
        <location filename="../src/HMMIO.cpp" line="499"/>
        <location filename="../src/HMMIO.cpp" line="504"/>
        <source>invalid_file_structure_near_%1</source>
        <translation>Invalid file structure near %1</translation>
    </message>
    <message>
        <location filename="../src/HMMIO.cpp" line="339"/>
        <source>ALPH must precede NULE in HMM save files</source>
        <translation>ALPH must precede NULE in HMM save files</translation>
    </message>
    <message>
        <location filename="../src/HMMIO.cpp" line="382"/>
        <source>value is not set for %1</source>
        <translation>Value is not set for &apos;%1&apos;</translation>
    </message>
    <message>
        <location filename="../src/HMMIO.cpp" line="518"/>
        <source>no // symbol found</source>
        <translation>No &apos;//&apos; symbol found</translation>
    </message>
    <message>
        <location filename="../src/HMMIO.cpp" line="72"/>
        <source>alphabet_not_set</source>
        <translation>Alphabet is not set</translation>
    </message>
    <message>
        <location filename="../src/HMMIO.cpp" line="636"/>
        <source>HMM models</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::HMMMSAEditorContext</name>
    <message>
        <source>do_hmmbuild</source>
        <translation type="obsolete">Build HMM model from alignment</translation>
    </message>
    <message>
        <location filename="../src/uHMMPlugin.cpp" line="217"/>
        <source>Build HMMER2 profile</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::HMMReadTask</name>
    <message>
        <location filename="../src/HMMIO.cpp" line="651"/>
        <source>Read HMM profile &apos;%1&apos;.</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::HMMSearchDialogController</name>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="111"/>
        <source>select_file_with_hmm_model</source>
        <translation>Select file with HMM model</translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="128"/>
        <source>hmm_file_not_set</source>
        <translation>HMM file not set!</translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="145"/>
        <source>error</source>
        <translation>Error!</translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="151"/>
        <source>Error</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="151"/>
        <source>Cannot create an annotation object. Please check settings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="162"/>
        <source>starting_search_process</source>
        <translation>Starting search process..</translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="165"/>
        <source>back_button</source>
        <translation>Hide</translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="181"/>
        <source>search_finished_with_errors_%1</source>
        <translation>HMM search finished with error: %1</translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="183"/>
        <source>search_finished_successfuly</source>
        <translation>HMM search finished successfuly!</translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="185"/>
        <source>ok_button</source>
        <translation>Search</translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="193"/>
        <source>progress_%1%</source>
        <translation>Progress: %1%</translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="166"/>
        <source>cancel_button</source>
        <translation>Cancel</translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="186"/>
        <source>close_button</source>
        <translation>Close</translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="76"/>
        <source>Cell BE optimized</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="60"/>
        <source>Search</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="61"/>
        <source>Close</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="79"/>
        <source>SSE optimized</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="81"/>
        <source>Conservative</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::HMMSearchTask</name>
    <message>
        <location filename="../src/u_search/HMMSearchTask.cpp" line="311"/>
        <source>parallel_hmm_search_task</source>
        <translation>Parallel HMM search</translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchTask.cpp" line="245"/>
        <source>invalid_hmm_alphabet_type</source>
        <translation>Invalid HMM alphabet!</translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchTask.cpp" line="27"/>
        <source>HMM Search</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchTask.cpp" line="249"/>
        <source>invalid_sequence_alphabet_type</source>
        <translation>Invalid sequence alphabet!</translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchTask.cpp" line="277"/>
        <source>can_t_find_amino</source>
        <translation>Amino translation is not available for the sequence alphabet!</translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchTask.cpp" line="19"/>
        <source>HMM search with &apos;%1&apos;</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::HMMSearchToAnnotationsTask</name>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="213"/>
        <source>raw_alphabet_not_supported</source>
        <translation>RAW alphabet is not supported!</translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="229"/>
        <source>annotation_obj_removed</source>
        <translation>Annotation object was removed</translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="207"/>
        <source>HMM search, file &apos;%1&apos;</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="255"/>
        <source>HMM profile used</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="258"/>
        <source>Task was not finished</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="263"/>
        <source>Result annotation table</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="264"/>
        <source>Result annotation group</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="265"/>
        <source>Result annotation name</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchDialogController.cpp" line="268"/>
        <source>Results count</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::HMMWriteTask</name>
    <message>
        <location filename="../src/HMMIO.cpp" line="671"/>
        <source>Write HMM profile &apos;%1&apos;</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::LocalWorkflow::HMMBuildPrompter</name>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="175"/>
        <source>For each MSA from &lt;u&gt;%1&lt;/u&gt;,</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="179"/>
        <source> and calibrate</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="181"/>
        <source>default</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="181"/>
        <source>custom</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="183"/>
        <source>%1 build%2 HMM profile using &lt;u&gt;%3&lt;/u&gt; settings.</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::LocalWorkflow::HMMBuildWorker</name>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="289"/>
        <source>Built HMM profile</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="295"/>
        <source>Calibrated HMM profile</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="115"/>
        <source>HMM Build</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="65"/>
        <source>HMM profile</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="75"/>
        <source>HMM strategy</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="75"/>
        <source>Specifies kind of alignments you want to allow.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="76"/>
        <source>Profile name</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="76"/>
        <source>Descriptive name of the HMM profile.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="83"/>
        <source>Calibrate profile</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="85"/>
        <source>Parallel calibration</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="88"/>
        <source>Fixed length of samples</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="90"/>
        <source>Mean length of samples</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="92"/>
        <source>Number of samples</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="94"/>
        <source>Standard deviation</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="96"/>
        <source>Random seed</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="211"/>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="212"/>
        <source>Incorrect value for seed parameter</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="230"/>
        <source>Schema name not specified. Using default value: &apos;%1&apos;</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="63"/>
        <source>Input MSA</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="64"/>
        <source>Input multiple sequence alignment for building statistical model.</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="65"/>
        <source>Produced HMM profile</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="83"/>
        <source>Enables/disables optional profile calibration.&lt;p&gt;An empirical HMM calibration costs time but it only has to be done once per model, and can greatly increase the sensitivity of a database search.</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="86"/>
        <source>Number of parallel threads that the calibration will run in.</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_build/HMMBuildWorker.cpp" line="115"/>
        <source>Builds a HMM profile from a multiple sequence alignment.&lt;p&gt;The HMM profile is a statistical model which captures position-specific information about how conserved each column of the alignment is, and which residues are likely.</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::LocalWorkflow::HMMLib</name>
    <message>
        <location filename="../src/HMMIOWorker.cpp" line="62"/>
        <source>HMM Profile</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/HMMIOWorker.cpp" line="132"/>
        <location filename="../src/HMMIOWorker.cpp" line="149"/>
        <source>HMM profile</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/HMMIOWorker.cpp" line="133"/>
        <source>Location</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/HMMIOWorker.cpp" line="156"/>
        <source>Read HMM Profile</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/HMMIOWorker.cpp" line="143"/>
        <source>Write HMM Profile</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/HMMIOWorker.cpp" line="70"/>
        <source>HMMER2 Tools</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/HMMIOWorker.cpp" line="132"/>
        <source>Input HMM profile</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/HMMIOWorker.cpp" line="133"/>
        <source>Location hint for the target file.</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/HMMIOWorker.cpp" line="143"/>
        <source>Saves all input HMM profiles to specified location.</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/HMMIOWorker.cpp" line="156"/>
        <source>Reads HMM profiles from file(s). The files can be local or Internet URLs.</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/HMMIOWorker.cpp" line="149"/>
        <source>Loaded HMM profile</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::LocalWorkflow::HMMReadPrompter</name>
    <message>
        <location filename="../src/HMMIOWorker.cpp" line="168"/>
        <source>Read HMM profile(s) from %1.</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>U2::LocalWorkflow::HMMReader</name>
    <message>
        <location filename="../src/HMMIOWorker.cpp" line="235"/>
        <source>Loaded HMM profile from %1</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::LocalWorkflow::HMMSearchPrompter</name>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="126"/>
        <source>For each sequence from &lt;u&gt;%1&lt;/u&gt;,</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="130"/>
        <source>Use &lt;u&gt;default&lt;/u&gt; settings.</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="130"/>
        <source>Use &lt;u&gt;custom&lt;/u&gt; settings.</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="132"/>
        <source>%1 HMM signals. %3&lt;br&gt;Output the list of found regions annotated as &lt;u&gt;%4&lt;/u&gt;.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="127"/>
        <source>using all profiles provided by &lt;u&gt;%1&lt;/u&gt;,</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::LocalWorkflow::HMMSearchWorker</name>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="212"/>
        <source>Bad sequence supplied to input: %1</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="236"/>
        <source>Found %1 HMM signals</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="55"/>
        <source>HMM profile</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="56"/>
        <source>Input sequence</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="58"/>
        <source>HMM annotations</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="73"/>
        <source>Result annotation</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="74"/>
        <source>Number of seqs</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="75"/>
        <source>Filter by high E-value</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="76"/>
        <source>Filter by low score</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="84"/>
        <source>HMM Search</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="157"/>
        <source>Power of e-value must be less or equal to zero. Using default value: 1e-1</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="166"/>
        <source>Value for attribute name is empty, default name used</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="208"/>
        <source>Search HMM signals in %1</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="55"/>
        <source>HMM profile(s) to search with.</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="57"/>
        <source>An input sequence (nucleotide or protein) to search in.</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="59"/>
        <source>Annotations marking found similar sequence regions.</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="73"/>
        <source>A name of the result annotations.</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/u_search/HMMSearchWorker.cpp" line="85"/>
        <source>Searches each input sequence for significantly similar sequence matches to all specified HMM profiles. In case several profiles were supplied, searches with all profiles one by one and outputs united set of annotations for each sequence.</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::LocalWorkflow::HMMWritePrompter</name>
    <message>
        <location filename="../src/HMMIOWorker.cpp" line="174"/>
        <source>unset</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/HMMIOWorker.cpp" line="178"/>
        <source>Save HMM profile(s) from &lt;u&gt;%1&lt;/u&gt; to &lt;u&gt;%2&lt;/u&gt;.</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::LocalWorkflow::HMMWriter</name>
    <message>
        <location filename="../src/HMMIOWorker.cpp" line="259"/>
        <source>Empty HMM passed for writing to %1</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/HMMIOWorker.cpp" line="259"/>
        <source>Unspecified URL for writing HMM</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/HMMIOWorker.cpp" line="270"/>
        <source>Writing HMM profile to %1</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::UHMMBuild</name>
    <message>
        <location filename="../src/u_build/uhmmbuild.cpp" line="184"/>
        <source>bogus configuration choice</source>
        <translation></translation>
    </message>
</context>
<context>
    <name>U2::UHMMSearch</name>
    <message>
        <source>UHMMSearch</source>
        <translation type="obsolete">HMM2 Search</translation>
    </message>
</context>
<context>
    <name>U2::uHMMPlugin</name>
    <message>
        <location filename="../src/uHMMPlugin.cpp" line="86"/>
        <source>uhmm_plugin</source>
        <translation>HMM2</translation>
    </message>
    <message>
        <location filename="../src/uHMMPlugin.cpp" line="86"/>
        <source>uhmm_plugin_desc</source>
        <translation>Based on HMMER 2.3.2 package
Biological sequence analysis using profile hidden Markov models</translation>
    </message>
    <message>
        <location filename="../src/uHMMPlugin.cpp" line="89"/>
        <source>Build HMM2 profile...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/uHMMPlugin.cpp" line="94"/>
        <source>Calibrate profile with HMM2...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/uHMMPlugin.cpp" line="99"/>
        <source>Search with HMM2...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <source>hmmcalibrate</source>
        <translation type="obsolete">HMM calibrate</translation>
    </message>
    <message>
        <location filename="../src/uHMMPlugin.cpp" line="196"/>
        <source>error</source>
        <translation>Error!</translation>
    </message>
    <message>
        <location filename="../src/uHMMPlugin.cpp" line="196"/>
        <source>neither_annotatedview_nor_pv_selection_found</source>
        <translation>Error! 
Select sequence in Project view or open sequence view</translation>
    </message>
</context>
<context>
    <name>UHMMSearch</name>
    <message>
        <source>UHMMSearch</source>
        <translation type="obsolete">HMM2 Search</translation>
    </message>
</context>
</TS>
