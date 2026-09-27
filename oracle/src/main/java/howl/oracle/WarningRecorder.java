package howl.oracle;

import ch.qos.logback.classic.Level;
import ch.qos.logback.classic.spi.ILoggingEvent;
import ch.qos.logback.core.AppenderBase;

import java.util.ArrayList;
import java.util.List;

/**
 * Records every WARN-or-higher event from any logger, so a file the oracle
 * reasoned over with a warning can be failed instead of diffed.
 *
 * <p>An oracle that ignores an axiom it does not support usually says so only
 * in a log line. Diffing through that line would certify HOWL against a
 * different theory (SPEC.md §10 item 1), so a warning is a failure of the
 * FILE, and the recorder is drained before each one.
 */
public final class WarningRecorder extends AppenderBase<ILoggingEvent> {
    private static final List<String> RECORDED = new ArrayList<>();

    @Override
    protected void append(ILoggingEvent event) {
        if (event.getLevel().isGreaterOrEqual(Level.WARN)) {
            synchronized (RECORDED) {
                RECORDED.add(event.getLevel() + " " + event.getLoggerName() + ": "
                        + event.getFormattedMessage());
            }
        }
    }

    static void record(String warning) {
        synchronized (RECORDED) {
            RECORDED.add(warning);
        }
    }

    /** Everything recorded since the last drain; empties the record. */
    static List<String> drain() {
        synchronized (RECORDED) {
            List<String> out = new ArrayList<>(RECORDED);
            RECORDED.clear();
            return out;
        }
    }
}
