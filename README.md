## Pear downstream development

This private downstream repository owns the selected Pear DXMT source checkpoint. It preserves upstream history, source languages, file notices and the original README below. Collaborator access is required for the linked Pear component repositories.

See [Pear source and verification handoff](pear/README.md) for the exact source manifest, component boundary, source checks, selected reconstruction and current verification limits. The runtime build/assembly owner is [pear-runtime](https://github.com/postmelee/pear-runtime); the application and game policy owner is [Pear](https://github.com/postmelee/pear).

The [selected reconstruction](https://github.com/postmelee/pear-runtime/blob/c8887f9edaba57dffe7772cc26fd19aa9571d451/locks/task56-reconstruction-v1.json) produced a separate development candidate. The fifteen fresh candidate3 controls passed with independent release; see the [current runtime status](https://github.com/postmelee/pear-runtime/blob/codex/task56/README.md#status-and-boundaries). Pear development selection, exact input inspection and metadata recovery passed; the seven synthetic fixtures also passed through the Pear entrypoint. Game copying/execution and public support remain unqualified. The original runtime and Preview selection remain unchanged.

The selected source cutover and development handoff are accepted locally by the existing owners. The [canonical cutover record](https://github.com/postmelee/pear-runtime/blob/codex/task56/provenance/source-cutover-task56.json) identifies the exact accepted commits, ownership limits and separate publication status. Final private publication refs are recorded separately in the Pear Task #56 handoff; acceptance does not activate a runtime.

---

# DXMT

A Metal-based translation layer for Direct3D 11 and 10 which allows running 3D applications on macOS using Wine.

For the current status of the project, please refer to the [project wiki](https://github.com/3Shain/dxmt/wiki).

The most recent development builds can be found [here](https://github.com/3Shain/dxmt/actions).


## Build

See [DEVELOPMENT.md](docs/DEVELOPMENT.md)
