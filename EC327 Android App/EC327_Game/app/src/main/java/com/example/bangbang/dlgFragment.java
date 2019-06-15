package com.example.bangbang;

import android.app.AlertDialog;
import android.app.Dialog;
import android.app.DialogFragment;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;

/**
 * Created by Steven on 12/7/2016.
 */

public class dlgFragment extends DialogFragment {
    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState){

        AlertDialog.Builder builder = new AlertDialog.Builder(getActivity());
        builder.setMessage("Game Over!")
                .setCancelable(true)
                .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {
                        launchWinActivity();
                    }
                });
        return builder.create();

    }

    private void launchWinActivity(){
        Intent intent = new Intent(getActivity(), Win.class);
        getActivity().startActivity(intent);
    }
}

